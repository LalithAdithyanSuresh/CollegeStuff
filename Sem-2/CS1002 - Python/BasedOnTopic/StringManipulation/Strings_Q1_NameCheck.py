# Name Check only alphabetss and points allowed


# s = input("Enter your name : ")
# Name = True
# for i in s.replace(' ','a').split('.'):
#     if not i.isalpha():
#         Name = False
#         break
# if Name==True : print("The Name is valid : ) ")
# else: print("The name is Invalid : (")
import random
import string

out1 = out2=""
while(1==1):
    s = ''.join(random.choices(string.ascii_uppercase + string.ascii_lowercase, k=20))
    if(s.isalpha()):
        s = list(s)
        for i in range(len(s)):
            for j in range(len(s)):
                if s[i].lower()<s[j].lower():
                    s[i],s[j] = s[j],s[i]
        out1="".join(s)
    else:
        out1="Invalid input"

    str1="".join(s)
    if(str1.isalpha()):
        l=list(str1)
        for i in range(len(l)):
            for j in range(len(l)-i-1):
                if(l[j].lower()>l[j+1].lower()):
                    temp=l[j]
                    l[j]=l[j+1]
                    l[j+1]=temp
        str3=""
        for k in l:
            str3+=k
        out2 = str3
    else:
        out2 = "Invalid input"

    if(out1 != out2):
        print()
        print("FOUND ERROR" + s)
        print("=>",out1)
        print("=>",out2)
        break
    else:
        print("works>>","".join(s))