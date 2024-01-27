# Display the odd numbers among N integers obtained from the user. Display
# the odd numbers in the same line, separated by a comma.


N = int(input("ENter the number of integers : "))
nums = []
for i in range(N):
    nums.append(int(input("Enter element - {} : ".format(i+1))))
for number in nums:
    if( number % 2 !=0):
        print(number,end=",")