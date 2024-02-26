# Program to find the palindorme substrings in a main string
String = input("Enter the string : ")
for i in range(len(String)):
    for j in range(i,len(String)):
        if(String[i:j+1]==String[i:j+1][::-1]):
            print(String[i:j+1],end=', ')