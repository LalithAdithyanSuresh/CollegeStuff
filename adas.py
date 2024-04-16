# Import necessary libraries
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.impute import SimpleImputer
from sklearn.pipeline import make_pipeline
from sklearn.metrics import accuracy_score
import streamlit as st

# Load dataset
data = pd.read_csv("train.csv")

# Clean the dataset (if necessary, handle missing values, outliers, etc.)
# For simplicity, we assume the dataset is already clean

# Preprocess the dataset (if necessary, feature engineering, data transformation, etc.)
# For simplicity, we assume the dataset is already preprocessed

# Exploratory Analysis (visualize data, summary statistics, etc.)
# For simplicity, we skip this step, but it's highly recommended in a real-world scenario

# One hot encoding for categorical variables
data = pd.get_dummies(data)

# Label encoding (if needed, for ordinal categorical variables)
# For simplicity, we assume all categorical variables are nominal and have been one-hot encoded

# Split dataset into features (X) and target variable (y)
X = data.drop("SalePrice", axis=1)
y = data["SalePrice"]

# Split the dataset into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Define the pipeline with an imputer, scaler, and logistic regression model
pipeline = make_pipeline(SimpleImputer(strategy='mean'), StandardScaler(), LogisticRegression())

# Fit the pipeline on the training data
pipeline.fit(X_train, y_train)

# Predictions
train_accuracy = accuracy_score(y_train, pipeline.predict(X_train))
test_accuracy = accuracy_score(y_test, pipeline.predict(X_test))

# Streamlit App
st.title("House Price Prediction App")

# Sidebar for user input
st.sidebar.header("User Input")
# Here, you can add input fields for user to provide values for different features

# Function to predict price based on user input
def predict_price(user_input):
    prediction = pipeline.predict(user_input)
    return prediction

# Get user input (example)
user_input = [[0]*len(X.columns)]  # Fill with appropriate values
prediction = predict_price(user_input)

# Display prediction
st.write("Predicted House Price:", prediction)

# Display model accuracy
st.write("Training Accuracy:", train_accuracy)
st.write("Test Accuracy:", test_accuracy)