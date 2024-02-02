# Print a hollow square

rows = int(input("enter the number of rows"))

for i in range(rows):
    tmpVal = 1
    for j in range(rows):
        if(i == 0 or j ==0 or j==rows-1 or i==rows-1 or j==i or i+j==rows-1):
            print(tmpVal,end=" ")
        else:
            print(" ",end=" ")
        tmpVal+=1
    print()