# Print all numbers between 1 and N (specified by the user) which when
# divided by a number, M, specified by the user will result in a remainder of
# 5. Count the number of values that satisfy the condition and compute their
# average and print it.


N = int(input("Enter the Natural Number Max Limit : "))
M = int(input("Enter the test case : "))
satisfiedNum = []
for i in range(1,N+1):
    if(i%M == 5):
        satisfiedNum.append(i)
        print(i,end=',')
print()
if(len(satisfiedNum) !=0):
    print("Count = {}\nAverage : {}".format(len(satisfiedNum),sum(satisfiedNum)/len(satisfiedNum)))
else:
    print("Count = 0\nAverage = 0")