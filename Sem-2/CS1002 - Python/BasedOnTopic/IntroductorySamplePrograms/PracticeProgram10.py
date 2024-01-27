# write  a program to print Pascal's triangle with the number of rows specified by the user.
# Pascal's triangle with 6 rows is as follows:
#       1
#      1 1
#     1 2 1
#   1  3 3  1
#  1 4  6  4 1
# 1 5 10 10 5 1


numberOfRows = int(input("Enter the number of rows"))
lastRow = [1]
currentRow = []
for i in range(numberOfRows):
    if(len(lastRow)==1):
        currentRow.append(lastRow[0])
        print(" "*(numberOfRows-i),currentRow[0])
        break
    