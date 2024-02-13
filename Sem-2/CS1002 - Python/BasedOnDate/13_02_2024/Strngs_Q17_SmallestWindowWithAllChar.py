# Find the smallest window with all the characters in a given string

Org = list(input("Enter the strin : "))
Uniq = list(set(Org))
S_window = len(Uniq)
Flag = False
while(Flag == False and S_window <= len(Org)):
    for i in range(len(Org)-S_window+1):
        Found = True
        for j in Uniq:
            if j not in Org[i:i+S_window]:
                Found = False
                break
        if Found == True:
            print('"'+''.join(Org[i:i+S_window])+'"  |  At Index : ',i,' to ',i+S_window)
            exit()
    S_window+=1

        
print(''.join(Org))