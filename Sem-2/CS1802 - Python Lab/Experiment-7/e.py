# Find the largest digit in a number

def LargestDigit(num):
    if(num==0):
        return 0
    else:
        return max(num%10,LargestDigit(num//10))
print(LargestDigit(int(input("Enter the number to find the largest Digit of : "))))