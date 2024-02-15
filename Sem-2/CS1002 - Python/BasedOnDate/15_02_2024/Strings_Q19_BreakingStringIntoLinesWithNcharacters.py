# Break the given string into lines with N characters specified by the user

MainString = list(input("Enter the String : "))
N = int(input("Enter the Value of N : "))
Lines = 0
while(Lines<(len(MainString)//N)):
    MainString.insert((Lines * N)+Lines , '\n')
    Lines+=1
print('Output :\n'+''.join(MainString).strip())