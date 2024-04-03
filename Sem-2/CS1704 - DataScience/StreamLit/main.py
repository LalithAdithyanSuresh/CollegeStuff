import streamlit as st
import pandas as pd
import pickle
Model = pickle.load(open(r'C:\Users\lalit\OneDrive - SSN Trust\College\CollegeStuff\Sem-2\CS1704 - DataScience\AUTOmpg\Model.pkl','rb'))
# file = pd.read_csv(r'C:\Users\lalit\OneDrive - SSN Trust\College\CollegeStuff\Sem-2\CS1704 - DataScience\AUTOmpg\auto-mpg.data',delimiter='\t')
# st.write(file)
# st.write(FILE)


st.write('The current Movie Title is : ',title)