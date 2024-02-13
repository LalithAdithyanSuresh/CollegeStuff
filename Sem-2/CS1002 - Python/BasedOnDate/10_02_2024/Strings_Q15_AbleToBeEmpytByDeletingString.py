# Check whether a string can be made empty by recursively deleting a substring

s = input("Enter the String : ")
d = input("Enter Deleting String : ")
while(d in s):
    s=s.replace(d,'')
if s=='':print("Yes")
else:print('No')