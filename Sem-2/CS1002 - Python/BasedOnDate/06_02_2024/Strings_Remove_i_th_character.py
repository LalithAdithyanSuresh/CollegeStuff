# Remove the i'th character from a string

s = input("Enter the string : ")
i = int(input("Enter the value of i : "))
print(s.replace(s[i-1],'',1))    # option -1
print(''.join(s.split(s[i-1],1))) # option -2