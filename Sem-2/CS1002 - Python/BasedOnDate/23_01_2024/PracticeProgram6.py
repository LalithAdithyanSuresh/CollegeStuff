# Display the odd numbers among N integers obtained from the user. Display
# the odd numbers in the same line, separated by a comma.


N = int(input("ENter the number of integers : "))
nums = []
for i in range(N):
    a = int(input("Enter element - {} : ".format(i+1)))
    if(a%2==0):
        nums.append(a)

print(*nums,sep=",")