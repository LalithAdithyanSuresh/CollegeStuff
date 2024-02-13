# Multiplication Table
N = int(input("Enter the Starting Integer : "))
for j in range(1,int(input("Enter the number of Multiplicatives Needed : "))+1):
    print(N," x ", j , " = ", N*j)