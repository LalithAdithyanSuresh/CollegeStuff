# Finding exponents with x as base and y as exponent

def Expo(x,y):
    if(y ==0):
        return 1
    else:
        return x * Expo(x,y-1)
    
print(Expo(int(input("Enter the Base : ")),int(input("Enter the exponent : "))))