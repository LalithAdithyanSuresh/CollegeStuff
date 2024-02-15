# Find the characters that appear odd number of times
CharCount = {}
for i in input("Enter the string : "):
    if(i in CharCount):CharCount[i]+=1
    else: CharCount[i]=1
for j,s in CharCount.items():
    if s%2 == 1:
        print(j," - ",s)