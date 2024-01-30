# Math Functions Usages

import math

print("(i) Acos(theta) - Bsin(theta)")
A = float(input("\tEnter the value for A : "))
B = float(input("\tEnter the value for B : "))
Theta = float(input("\tEnter the value for Theta : "))
print("\t\tAnswer : {:0.2E}".format((A * math.cos(Theta)) - (B * math.sin(Theta))))

print("(ii) Acos(2 pi n)")
A = float(input("\tEnter the value for A : "))
n = float(input("\tEnter the value for n : "))
print("\t\tAnswer : {:0.2E}".format(A * math.cos(2 * math.pi * n)))

print("(iii) e^an")
a = float(input("\tEnter the value for a : "))
n = float(input("\tEnter the value for n : "))
print("\t\tAnswer : {:0.2E}".format(math.exp(a*n)))

print("(iv) euclidian Distance")
x1 = float(input("\tEnter the value for X1 : "))
y1 = float(input("\tEnter the value for Y1 : "))
x2 = float(input("\tEnter the value for X2 : "))
y2 = float(input("\tEnter the value for Y2 : "))
print("\t\tAnswer : {:0.2E}".format(math.sqrt(math.pow(x1-x2,2) + math.pow(y1-y2,2))))

print("(v) degree to radians")
a = float(input("\tEnter the value for theta in degrees : "))
print("\t\tAnswer : {:0.2E}".format(math.radians(a)))

print("(v) log with base 10 and 2")
x = float(input("\tEnter the value for x : "))
print("\t\tAnswer : log base 10 = {:0.2E}  |  base 2 = {:0.2E}".format(math.log10(x),math.log2(x)))
