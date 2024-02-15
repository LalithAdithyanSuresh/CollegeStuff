# Find the number of time to rotate a string to get another string
S1 = input("Enter Original String : ")
S2 = input("Enter Rotating String : ")
RR = 0
RL = 0
if(len(S1)==len(S2)):
    Rotate = S2
    while(RR <len(S2)+2):
        Rotate = Rotate[-1]+Rotate[:-1]
        RR +=1
        if(Rotate == S1):
            break
    Rotate = S2
    while(RL <len(S2)+2):
        Rotate = Rotate[1:]+Rotate[0]
        RL +=1
        if(Rotate == S1):
            break
    if(RR>len(S1) or RL>len(S1)):
        print("The string cannot be rotated")
    else:
        print("Right Rotated ",RR," Time")
        print("Left Rotated ",RL," Time")
