# In a dictionary print the minimum value

dict  = eval(input("Enter the dictionary : "))
m = 9999999999999
M = ''
for i,j in enumerate(dict):
    if i < m:
        m = i
        M = j

print(M)