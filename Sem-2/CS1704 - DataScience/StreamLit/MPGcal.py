import streamlit as st
import pickle
import numpy as np
Model = pickle.load(open(r'C:\Users\lalit\OneDrive - SSN Trust\College\CollegeStuff\Sem-2\CS1704 - DataScience\AUTOmpg\Model.pkl','rb'))


st.write(Model.predict(np.array([1,2,3,4,5,6,7,8,10]).reshape(1,-1)))