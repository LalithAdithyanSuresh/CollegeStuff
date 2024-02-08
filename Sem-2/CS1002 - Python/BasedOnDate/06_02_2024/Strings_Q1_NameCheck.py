# Name Check only alphabetss and points allowed


s = input("Enter your name : ")
Name = True
for i in s.replace(' ','a').split('.'):
    if not i.isalpha():
        Name = False
        break
if Name==True : print("The Name is valid : ) ")
else: print("The name is Invalid : (")