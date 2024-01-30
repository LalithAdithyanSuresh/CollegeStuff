# Write a program to print Floyd's triangle with the number of rows specifed by the user. Floyd's triangle with 4 rows is a as foolows : 
# 1
# 2 3
# 4 5 6
# 7 8 9 10

numberOfRows = int(input("Enter the number of rows : "))
currentNum = 1
for i in range(1,numberOfRows+1):
    for j in range(i):
        print(currentNum,end = ' ')
        currentNum+=1
    print()