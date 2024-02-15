# Find the frequency of Each Characters

CharCount = {}
for i in input("Enter the String : "):
    if i in CharCount:CharCount[i]+=1
    else:CharCount[i] = 1
for i,j in CharCount.items():
    print(i,' : ',j)

# without list,dicts
b = input("Enter the string :")
s =''
for i in b:
    if i not in s:
        s+=i
        print(i," : ",b.count(i))
    