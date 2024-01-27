# Generate the Fibonacci series up to N. Obtain the value of N from the user.

N = int(input("Enter the Series elemnents cap (N): "))
tempList = [0,1]

for i in range(N):
    print(tempList[1],end=',')
    tempList[0],tempList[1] = tempList[1],tempList[0]+tempList[1] 