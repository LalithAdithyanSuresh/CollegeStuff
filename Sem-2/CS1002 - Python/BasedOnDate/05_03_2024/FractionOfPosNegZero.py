# A program to find the fraction of positive numbers, negative numbers and zeros to the total elements

pos = neg = zero = 0
l = [1,4,0,6,8,-3,0,-6,-2,-6,0]
for i in l:
    if(i>0):
        pos+=1
    elif(i<0):
        neg+=1
    else:
        zero+=1
print("Fractions of\n\tPositive = {:.3f}\n\tNegative = {:.3f}\n\tZeros = {:.3f}".format(pos/len(l),neg/(len(l)),zero/len(l)))