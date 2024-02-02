# Produce the following pattern
 
    # #
   ## ##
  ### ###
 #### ####


N = int(input("Enter the number of rows : "))
for rowNum in range(1,N+1):
    # size of empty spaces = (N - rowNum)
    # size of each half of the staircase = rowNum
    print(" "*(N-rowNum)+ "#"*rowNum + " " + "#"*rowNum)