# Printing list of prime numbers Between 1 and N 

for i in range(2,int(input("Enter N : "))+1):
    f=0
    for j in range(2,(i//2)+1):
        if(i%j == 0):
            f = 1
            break
    if(f==0):
        print(i,end = ", ")
