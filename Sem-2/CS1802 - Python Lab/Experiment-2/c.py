#Calculate Salary of an employee
import math

BP = float(input("Enter the basic Pay : "))
DA = float(input("Enter the Persent of DA: "))
HRA = float(input("Enter the Persent of HRA: "))


print("Salary = {:0.2f}".format(BP + (BP * DA/100) + (BP * HRA/100) - (BP *0.12)))