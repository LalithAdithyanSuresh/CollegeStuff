import streamlit as st
from sklearn.neighbors import KNeighborsClassifier
import pickle
import numpy as np

file = open("BestModel.pkl",'rb')
dataPackage = pickle.load(file)

model = dataPackage[0]
k_value = dataPackage[1]
score = dataPackage[2]
columns = dataPackage[3]

st.write("Using K-Value : {}".format(k_value))
st.write("Model Accuracy : {}".format(score))

val = [0 for _ in range(len(columns[1:]))]
for i, column_name in enumerate(columns[1:]):
    val[i] = st.number_input(column_name, 0, 15)
    
st.write("Model Predicted Letter : {}".format(model.predict(np.array(val).reshape(1, -1))[0]))
