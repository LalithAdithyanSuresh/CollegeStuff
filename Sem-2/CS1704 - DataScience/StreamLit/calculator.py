import streamlit as st
st.write("### Calculator")
a = st.number_input('Value of a')
b = st.number_input('Value of b')
c = st.number_input('Value of c')
d = st.number_input('Value of d')

opt = st.radio('Operation',['Addition','Subtraction','Division','Multiply'])
if opt == 'Addition':
    st.write(a + b + c + d)
elif opt == 'Subtraction':
    st.write(a - b - c - d)
elif opt == 'Division':
    try:
        st.write(a / b / c / d)
    except ZeroDivisionError:
        st.write(0)
else:
    st.write(a * b * c * d)