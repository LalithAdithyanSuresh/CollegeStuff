import math
def Fact(N):
    if(N<=1):
        return 1
    return N*Fact(N-1)

def SinSum(rad,terms,c = 0):
    if(terms == c):
        return 0
    else:
        return math.pow(rad,(c*2+1))/ Fact(c*2+1) + math.pow(-1,c+1) * (SinSum(rad,terms,c+1))
    
def CosSum(rad,terms,c=0):
    if(terms == c):
        return 0
    else:
        return math.pow(rad,(c*2))/ Fact(c*2) + math.pow(-1,c+1) * (CosSum(rad,terms,c+1))
    

N = int(input("Enter the number of terms : "))
deg = float(input("Enter the in degrees : "))
radians = deg*(3.14/180)
print(SinSum(radians,N))
print(CosSum(radians,N))