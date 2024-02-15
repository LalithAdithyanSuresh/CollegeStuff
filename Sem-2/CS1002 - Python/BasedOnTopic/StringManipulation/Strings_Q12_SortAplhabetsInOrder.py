# Sort All Alphabets in alphabetical order
import string
s = input("Enter the string : ")
if(s.isalpha()):
    s = list(s)
    for i in range(len(s)):
        for j in range(len(s)):
            if s[i].lower()<s[j].lower():
                s[i],s[j] = s[j],s[i]
    print("Arranged : "+"".join(s))
else:
    print("Invalid input")