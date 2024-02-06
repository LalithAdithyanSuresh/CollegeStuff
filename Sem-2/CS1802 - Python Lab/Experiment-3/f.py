SideLengths = [float(input("Enter the length of side - {} : ".format(i))) for i in range(1,5)]
Angles = [float(input("Enter the degree of angle - {} : ".format(i))) for i in range(1,5)]
var = 0
for i in Angles:
    var+=i
if var== 360:
    if len(set(Angles))==1:
        if len(set(SideLengths))==1: print("The given Quadrilateral is a Square")
        if len(set(SideLengths))==2: print("The given Quadrilateral is a Rectangle")
    else:
        print("The Given Dimensions is for a Quadrilateral\nBut does not reperesent a Square or a Rectangle")
else:
    print("The Given Dimensions is not valud for a Quadrilateral")