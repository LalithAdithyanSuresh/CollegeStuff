from sqlalchemy import column
import streamlit as st
import pickle

file = open("BestModel.pkl",'rb')
dataPackage = pickle.load(file)
k_value = dataPackage[1]
model = dataPackage[0]
columns = dataPackage[3]
score = dataPackage[2]
st.write("Using K-Value : {}".format(k_value))
st.write("Model Accuracy : {}".format(score))
val = [0 for x in range(len(columns))]
for i in range(len(columns)):
    val[i] = st.number_input(columns[i],0,15)

st.text("Hello")
