# Program to find area of specified Shapes
import math

print("Finding area of Triangle : ")
b = input("\tEnter the Base length of the triangle : ")
h = input("\tEnter the Height of the triangle : ")
print("\t\tThe area is = {:0.2f}".format((0.5 * float(b) * float(h))))

print("Finding area of Parallelogram : ")
b = input("\tEnter the Base length : ")
h = input("\tEnter the Height : ")
print("\t\tThe area is = {:0.2f}".format((float(b) * float(h))))

print("Finding area of Cylinder : ")
r = input("\tEnter the Radius : ")
h = input("\tEnter the Height : ")
print("\t\tThe area is = {:0.2f}".format((2* math.pi * float(r)  * (float(r) + float(h)))))

print("Finding area of Cone : ")
r = input("\tEnter the Radius : ")
l = input("\tEnter the Length : ")
print("\t\tThe area is = {:0.2f}".format((math.pi * float(r) * ( float(r) + float(l)))))

print("Finding area of Sphere : ")
r = input("\tEnter the Radius : ")
print("\t\tThe area is = {:0.2f}".format((4 * math.pi * math.pow(float(r),2))))

print("Finding area of Prism : ")
w = float(input("\tEnter the Width : "))
l = float(input("\tEnter the Length : "))
h = float(input("\tEnter the Height : "))
print("\t\tThe area is = {:0.2f}".format((2 * (w*l + h*l + h*w))))


