# Write a function to check if the given string is a happy or a perfect number or both


def HappyNum(N):
    sum = 0
    for i in range(1,N):
        if(N%i==0):
            sum+=i
    if sum == N:return True
    return False

def PerfectNum(N):
    while(N!=1):
        sum = 0
        for x in str(N):
            sum+= int(x)**2
        if(len(str(sum)) == 1 and sum !=1):
            return False
        N = sum
    return True

N = int(input("Enter the Integer : "))
print(HappyNum(N),PerfectNum(N))