r = float(input("Enter the Radius of the circle : "))
x,y = eval("[" + input("Enter the x and y coordinates seperated by comman ( x,y ) : ")+ "]")
if((x**2 + y**2)**(1/2) > r):
    print("Outside the circle")
elif((x**2 + y**2)**(1/2) < r):
    print("Inside the circle")
else:
    print("On the Circumference of the circle")
