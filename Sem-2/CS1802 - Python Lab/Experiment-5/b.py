# Program to find the number of substrings having the same starting and ending character as the Main String

MainString = input("ENter the String : ")
Counts = 0
S = 0
E = 1
while(S < E):
    pos1 = MainString.find(MainString[0],S)
    if(pos1==-1):
        break
    E = S+1
    while(MainString.find(MainString[-1],E)!=-1):
        E = MainString.find(MainString[-1],E)+1
        Counts+=1
    S = pos1+1
print(Counts)