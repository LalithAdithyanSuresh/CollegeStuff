import streamlit as st
import pickle
import numpy as np
Model = pickle.load(open(r'C:\Users\lalit\OneDrive - SSN Trust\College\CollegeStuff\Sem-2\CS1704 - DataScience\AUTOmpg\Model.pkl','rb'))

st.title("AutoMPG prediction Models")
st.write("Predicted MPG : " + str(Model.predict(np.array([st.number_input("Displacement"),st.number_input("Number of Cylinders"),st.number_input("HorsePower"),st.number_input("Weight"),st.number_input("Acceleration"),st.number_input("Model Year"),st.number_input("Origin"),st.number_input("Brand"),st.number_input("Model")]).reshape(1,-1))[0]))
