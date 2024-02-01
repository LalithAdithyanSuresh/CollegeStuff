# write  a program to print Pascal's triangle with the number of rows specified by the user.
# Pascal's triangle with 6 rows is as follows:
#       1
#      1 1
#     1 2 1
#   1  3 3  1
#  1 4  6  4 1
# 1 5 10 10 5 1

# without any lists

n = int(input("Enter the number of rows : "))
pval = 1
print(" "*(n-1),1)
for i in range(1,n+1):
    print(" "*(n-i),end="")
    for j in range(i+1):
        if(j == 0 or j==i):
            print("1",end = " ")
            pval = 1
        else:
            print("{}".format((pval*(i-j+1))//j),end=" ")
            pval = (pval*(i-j+1))//j
    print()
        