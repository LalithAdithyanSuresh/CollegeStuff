# Break the given string into lines with N characters specified by the user

MainString = input("Enter the String : ")
N = int(input("Enter the Value of N : "))
Lines = 0
while(Lines<(len(MainString)//N)):
    MainString = MainString[0:(Lines * N)+Lines]+ '\n'+MainString[(Lines * N)+Lines:]
    Lines+=1
print('Output :\n'+MainString.strip())