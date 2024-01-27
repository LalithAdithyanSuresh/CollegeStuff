# Prompt the user to enter three numbers and calculate the sum, mean,
# maximum and minimum values and display the results.

a = int(input("Enter The value for a : "))
b = int(input("Enter The value for b : "))
c = int(input("Enter The value for c : "))

print("sum = {}\nmean = {}\nMax = {}\nMin = {}".format(a+b+c,(a+b+c)/3,max([a,b,c],min([a,b,c]))))