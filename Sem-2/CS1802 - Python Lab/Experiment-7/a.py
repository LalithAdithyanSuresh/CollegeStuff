# Recursive program to find the factorial of a given number

def Fact(num):
    if(num==1):
        return 1    
    else:
        return num * Fact(num-1)
    
print(Fact(int(input("Enter Number : "))))