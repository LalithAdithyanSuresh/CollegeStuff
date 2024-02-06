# Find the frequency of Each Characters

CharCount = {}
for i in input("Enter the String : "):
    if i in CharCount:CharCount[i]+=1
    else:CharCount[i] = 1
for i,j in CharCount.items():
    print(i,' : ',j)