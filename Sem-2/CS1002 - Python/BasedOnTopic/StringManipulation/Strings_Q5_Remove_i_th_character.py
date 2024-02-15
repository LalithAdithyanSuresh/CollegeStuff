# Remove the i'th character from a string

s = input("Enter the string : ")
i = int(input("Enter the value of i : "))
print(s[:i]+s[i+1:])