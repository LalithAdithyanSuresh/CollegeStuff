# Program to find Simple and Compound Interest
import math

p = float(input("Enter the Principle Amount : "))
r = float(input("Enter the Rate Of Interest : "))
t = float(input("Enter the Term of Deposit : "))
n = float(input("Enter the Interest Compounds in a year : "))

print("Simple Interest = {:0.4f}".format((p * t * r)/100))
print("Compound Interest = {:0.4f}".format((p * math.pow((1 + r/n),n*t) - p)))