# Obtain the mark scored by a user out of 100, as an integer and, categorize
# it as follows:
# 90 <= mark <= 100 outstanding
# 80 <= mark < 90 excellent
# 70 <= mark < 80 good
# 60 <= mark < 70 average
# 50 <= mark < 60 below average
# mark < 50 poor

mark = int(input("Enter the mark obtained : "))
if(mark<=100 and mark > 90):
    print("Outstanding")
elif(mark >= 80):
    print("Excellent")
elif(mark >= 70):
    print("Good")
elif(mark >= 60):
    print("Average")
elif(mark >= 50):
    print("Below Average")
elif(mark >= 0):
    print("Poor")
else:
    print("Invalid mark")