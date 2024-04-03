# Program to rename key in a dictionary

dict = eval(input("Enter the Dictionary : "))
orig = input("Enter orignal Key : ")
rena = input("Enter rename Key : ")
dict[rena] = dict.pop(orig)
print(dict)