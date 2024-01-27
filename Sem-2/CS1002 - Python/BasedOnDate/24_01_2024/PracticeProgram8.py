#  Print all the prime numbers upt to a number N given by the user.

N = int(input("Enter the value of N : "))
for i in range(2,N+1):
    f=1
    for j in range(2,int(i/2) + 1):
        if(i%j == 0):
            f = 0
            break
    if(f==1):
        print(i,end = " ")