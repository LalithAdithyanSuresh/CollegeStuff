# Finding Combinations using n and r values
def Fact(num):
    if(num==1):
        return 1    
    else:
        return num * Fact(num-1)
def Combinations(n,r):
    return Fact(n)/(Fact(r)*Fact(n-r))
print('nCr = ',Combinations(int(input("Enter n: ")),int(input("Enter r: "))))