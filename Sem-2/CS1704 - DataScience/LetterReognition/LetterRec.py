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
st.title("KNN Classification for letter Recognition")
st.write("Using K-Value : {}".format(k_value))
st.write("Model Accuracy : {}".format(score))

COL1,COL2 = st.columns(2)

val = [0 for _ in range(len(columns[1:]))]
for i, column_name in enumerate(columns[1:]):
    if(i%2 == 0):
        col = COL1
    else:
        col = COL2
    val[i] = col.number_input(column_name, 0, 15)

st.write("<div style='font-size:40px'>Model Predicted Letter : {}</div>".format(model.predict(np.array(val).reshape(1, -1))[0]),unsafe_allow_html=True)
