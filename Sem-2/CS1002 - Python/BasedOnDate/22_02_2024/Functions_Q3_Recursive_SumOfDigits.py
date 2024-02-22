# Recursive function to find the sum of digits

def SumOfDigits(N):
    if(N == 0):
        return 0
    else:
        return N%10 + SumOfDigits(N//10)

print(SumOfDigits(int(input("Enter the integer : "))))