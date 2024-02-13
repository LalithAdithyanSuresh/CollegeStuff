# Greatest Common Divisor of two numbers
M = int(input("Enter Number - 1 : "))
n = int(input("Enter Number - 2 : "))
if(n>M):
    n,M = M,n
for i in range(n,0,-1):
    if (M%i==0 and n%i==0):
        print("Greatest Common Divisor is : ",i)
        break