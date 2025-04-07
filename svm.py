import pandas as pd
import numpy as np
import itertools
import warnings
from time import time
import json # For printing config nicely

# Core ML Libraries
from sklearn.model_selection import train_test_split as sk_train_test_split
from sklearn.preprocessing import StandardScaler, MinMaxScaler, RobustScaler, OneHotEncoder
from sklearn.decomposition import PCA
from sklearn.svm import SVC
from sklearn.pipeline import Pipeline
from sklearn.compose import ColumnTransformer, make_column_selector
from sklearn.metrics import accuracy_score, f1_score # Choose your metric
from sklearn.exceptions import ConvergenceWarning

print("--- Script Start ---")

# --- 1. Configuration Parameters ---
SCORING_METRIC = accuracy_score
RANDOM_STATE = 42
VERBOSE = 1

# --- Parameter Grids to Search ---
SCALERS_TO_TRY = {
    'StandardScaler': StandardScaler(),
    'MinMaxScaler': MinMaxScaler(),
    'None': None,
}
PCA_N_COMPONENTS_OPTIONS = [0.95, 4, None] # Use iris's max features (4) or variance
SVM_PARAM_GRID = {
    'svm__C': [1, 10],
    'svm__kernel': ['rbf', 'linear'],
    'svm__gamma': ['scale', 0.1],
    'svm__decision_function_shape': ['ovo', 'ovr'] # **** ADDED THIS ****
    #'svm__degree': [3] # Only relevant for poly
}

# --- 2. Load Data (Using Iris) ---
print("Loading Iris dataset...")
from sklearn.datasets import load_iris
iris = load_iris()
X_df = pd.DataFrame(iris.data, columns=iris.feature_names)
y_series = pd.Series(iris.target, name='target')

# --- Split Data ---
X_train, X_test, y_train, y_test = sk_train_test_split(
    X_df, y_series, test_size=0.3, random_state=RANDOM_STATE, stratify=y_series
)

print("--- Input Data Info ---")
print("X_train Info:")
X_train.info()
print(f"\nX_train shape: {X_train.shape}")
print(f"y_train shape: {y_train.shape}")
# ... other info ...

# --- 3. Feature Identification ---
print("\nIdentifying feature types...")
# (Using DataFrame selectors)
numerical_features = make_column_selector(dtype_include=np.number)(X_train)
categorical_features = make_column_selector(dtype_include=['object', 'category'])(X_train)
boolean_features = make_column_selector(dtype_include=np.bool_)(X_train)
print(f"  Numerical: {numerical_features}")
print(f"  Categorical: {categorical_features}") # Will be empty for Iris
print(f"  Boolean: {boolean_features}") # Will be empty for Iris
if not numerical_features and not categorical_features and not boolean_features:
     raise ValueError("No features identified.")

# --- 4. Expand SVM Parameter Combinations ---
print("\nExpanding SVM parameter combinations...")
svm_combinations = []
# Treat kernel specifics separately, group the rest
svm_base_params = {
    k: v for k, v in SVM_PARAM_GRID.items()
    if k not in ['svm__kernel', 'svm__gamma', 'svm__degree']
}
kernel_options = SVM_PARAM_GRID.get('svm__kernel', ['rbf'])
gamma_options = SVM_PARAM_GRID.get('svm__gamma', ['scale'])
degree_options = SVM_PARAM_GRID.get('svm__degree', [3])

# Generate combinations of base parameters (C, decision_function_shape, etc.)
base_param_product = list(itertools.product(*[[(k, v) for v in values] for k, values in svm_base_params.items()]))
if not base_param_product: base_param_product = [{}] # Handle case with no base params

# Combine base params with kernel-specific ones
for kernel in kernel_options:
    for base_params_tuple in base_param_product:
        base_p_dict = dict(base_params_tuple) if isinstance(base_params_tuple, tuple) else base_params_tuple
        p = {'svm__kernel': kernel}
        p.update(base_p_dict) # Add C, decision_function_shape etc.

        if kernel == 'linear':
            # Linear doesn't use gamma/degree meaningfully
            svm_combinations.append(p.copy()) # Add the combination
        elif kernel == 'poly':
            poly_prod = list(itertools.product(gamma_options, degree_options))
            for gamma_val, degree_val in poly_prod:
                p_poly = p.copy()
                p_poly['svm__gamma'] = gamma_val
                p_poly['svm__degree'] = degree_val
                svm_combinations.append(p_poly)
        else: # rbf, sigmoid, etc. (use gamma)
            for gamma_val in gamma_options:
                p_rbf = p.copy()
                p_rbf['svm__gamma'] = gamma_val
                svm_combinations.append(p_rbf)

print(f"Generated {len(svm_combinations)} SVM parameter sets.")

# --- 5. Initialize Tracking ---
best_score = -np.inf
best_config = {}
best_pipeline_details = {}
iteration_count = 0
total_iterations = len(SCALERS_TO_TRY) * len(PCA_N_COMPONENTS_OPTIONS) * len(svm_combinations) # Calculation is correct

print(f"\nTotal combinations to check: {total_iterations}")
if total_iterations == 0: raise ValueError("Zero combinations.")
start_time = time()

# --- 6. Iterate Through All Combinations ---
print("\nStarting pipeline evaluation loop...")
for scaler_name, scaler_obj in SCALERS_TO_TRY.items():
    for n_components in PCA_N_COMPONENTS_OPTIONS:
        # --- 6.1 Build Preprocessor ---
        pipeline_steps = []
        preprocessor_transformers = []
        # (Preprocessor logic remains the same - builds based on identified features)
        if numerical_features:
            num_pipeline = Pipeline([('num_scaler', scaler_obj if scaler_obj else 'passthrough')])
            preprocessor_transformers.append(('numerical', num_pipeline, numerical_features))
        # No categorical/boolean for Iris, these blocks will be skipped
        if categorical_features:
            cat_pipeline = Pipeline([('onehot_cat', OneHotEncoder(handle_unknown='ignore', sparse_output=False))])
            preprocessor_transformers.append(('categorical', cat_pipeline, categorical_features))
        if boolean_features:
             bool_pipeline = Pipeline([('onehot_bool', OneHotEncoder(drop='if_binary', sparse_output=False))])
             preprocessor_transformers.append(('boolean', bool_pipeline, boolean_features))
        if preprocessor_transformers:
             preprocessor = ColumnTransformer(transformers=preprocessor_transformers, remainder='drop')
             pipeline_steps.append(('preprocessing', preprocessor))

        # --- 6.2 Add PCA Step ---
        pca_step_added = False
        if n_components is not None:
            # PCA Validation Logic
            n_samples_train = X_train.shape[0]
            n_features_effective = len(numerical_features) # Only numerical for Iris
            max_pca_components = min(n_samples_train, n_features_effective)
            valid_pca = False
            current_pca_n = n_components # Use original value for reporting

            if isinstance(n_components, float) and 0 < n_components < 1:
                if max_pca_components > 0 : valid_pca = True
            elif isinstance(n_components, int):
                 if 0 < n_components <= max_pca_components: valid_pca = True

            if valid_pca:
                pipeline_steps.append(('pca', PCA(n_components=n_components, random_state=RANDOM_STATE)))
                pca_step_added = True
            else:
                 if VERBOSE > 0: print(f"  Skipping invalid PCA setting n_components={current_pca_n} (max: {max_pca_components})")
                 # Continue to the next n_components value, skip SVM loop for this PCA
                 continue

        # --- 6.3 Iterate through SVM parameters ---
        for svm_params in svm_combinations:
            iteration_count += 1
            if VERBOSE > 0 and iteration_count % (max(1, total_iterations // 10)) == 0: # Print progress ~10 times
                elapsed = time() - start_time
                print(f"  Iteration {iteration_count}/{total_iterations}... ({elapsed:.1f}s elapsed)")

            # Add SVM Step
            current_svm_params = {k.replace('svm__', ''): v for k, v in svm_params.items()}
            svc = SVC(**current_svm_params, random_state=RANDOM_STATE, probability=False)
            current_pipeline_steps = pipeline_steps + [('svm', svc)]

            # Create and Run Pipeline
            pipeline = Pipeline(steps=current_pipeline_steps)

            # **** UPDATED Description ****
            current_config_desc = {
                "Scaler": scaler_name if numerical_features else "N/A",
                "Encoding": "OneHot" if categorical_features or boolean_features else "N/A",
                "PCA": n_components if pca_step_added else "None", # Use original value
                "SVM Kernel": current_svm_params.get('kernel','N/A'),
                "SVM C": current_svm_params.get('C','N/A'),
                "SVM Gamma": current_svm_params.get('gamma') if current_svm_params.get('kernel') != 'linear' else "N/A",
                "SVM Shape": current_svm_params.get('decision_function_shape', 'N/A') # ADDED
            }

            try:
                # Train, Predict, Evaluate, Track Best (logic remains the same)
                with warnings.catch_warnings():
                    warnings.simplefilter("ignore") # Suppress all warnings during grid search
                    pipeline.fit(X_train, y_train)
                    y_pred = pipeline.predict(X_test)
                    score = SCORING_METRIC(y_test, y_pred)

                if VERBOSE > 1:
                     # Use json.dumps for cleaner multiline printing if needed
                     print(f"    Config: {json.dumps(current_config_desc)} -> Score: {score:.4f}")

                if score > best_score:
                    best_score = score
                    best_config = current_config_desc
                    best_pipeline_details = {'steps': pipeline.steps, 'params': pipeline.get_params(deep=True)}
                    if VERBOSE > 0:
                        print(f"*** New Best Score: {best_score:.4f} ***")
                        print(f"    Best Config: {json.dumps(best_config)}")

            except Exception as e: # Catch potential errors during fit/predict
                if VERBOSE > 0:
                    print(f"  Error on config: {json.dumps(current_config_desc)} | {type(e).__name__}: {e}")
                continue

# --- 7. Final Output ---
end_time = time()
print(f"\nOptimization finished in {end_time - start_time:.2f} seconds.")

if not best_config: # Check if best_config dictionary is empty
    print("No successful pipeline execution completed.")
else:
    print(f"\n--- Best Result ---")
    print(f"Best Score ({SCORING_METRIC.__name__}): {best_score:.4f}")
    print("Best Configuration Found:")
    print(json.dumps(best_config, indent=2)) # Pretty print the best config

print("\n--- Script End ---")
