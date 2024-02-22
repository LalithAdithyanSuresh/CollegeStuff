# Write a recursive function to count down form N

def CountDown(N):
    print(N)
    if(N==0):
        return
    else:
        CountDown(N-1)

CountDown(int(input("Enter the countdown starting value : ")))