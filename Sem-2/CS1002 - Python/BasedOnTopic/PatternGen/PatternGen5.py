# write  a program to print Pascal's triangle with the number of rows specified by the user.
# Pascal's triangle with 6 rows is as follows:
#       1
#      1 1
#     1 2 1
#   1  3 3  1
#  1 4  6  4 1
# 1 5 10 10 5 1


numberOfRows = int(input("Enter the number of rows : "))
MaxLenOfInt = 0

# Intitialising Matrix of Size N x (N*2)-1 with zeros
Matrix = []
for row in range(numberOfRows):
    NewRow = []
    for column in range((numberOfRows * 2)-1):
        NewRow.append(0)
    Matrix.append(NewRow)

# Starting value of 1 in the middle of the matrix
Matrix[0][numberOfRows-1] = 1

for RowNum , row in enumerate(Matrix):
    for ColNum , col in enumerate(row):
        if(col != 0):
            try:
                Matrix[RowNum+1][ColNum-1] += col
            except:
                pass
            try:
                Matrix[RowNum+1][ColNum +1] +=col
            except:
                pass
        if(len(str(col))>MaxLenOfInt):  #Updating the Max int length
            MaxLenOfInt = len(str(col))

# Printing Matrix by replacing zeros with empty spaces
for i in Matrix:
    for j in i:
        if(j!=0):
            print(str(j).rjust(MaxLenOfInt),end="")
        else:
            print(" "*MaxLenOfInt,end="")
    print()