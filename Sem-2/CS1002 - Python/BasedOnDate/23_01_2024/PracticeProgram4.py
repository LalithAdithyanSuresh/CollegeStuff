# A company pays its employees at an hourly rate and provides an overtime
# pay that is 1.5 times the hourly rate, for every additional hour, if an
# employee has worked over 40 hours. Calculate the pay earned by an
# employee, given the number of hours he has worked. Round off the pay to
# 2 decimal places.
hoursWorked = int(input("Enter the number of hours worked : "))
payForEachHour = int(input("Enter the payout for each hour of work : "))

hoursOvertime = max(0,hoursWorked-40)
hoursNormal = min(40,hoursWorked)
payOut = hoursNormal * payForEachHour + (hoursOvertime * 1.5 * payForEachHour)
print("The payout is : ",payOut)