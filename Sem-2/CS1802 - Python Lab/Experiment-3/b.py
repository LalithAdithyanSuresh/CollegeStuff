year = int(input("Enter the year : "))
print("Leap Year : ",end="")
if((year%4 ==0 or year%400==0) and not year%100==0):
    print("True")
else:
    print("false")