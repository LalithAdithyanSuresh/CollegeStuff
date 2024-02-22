# Write a recursive function to delete a digit at a given position

def DeleteDigit(N,pos):
    if(len(str(N))==0):
        return ''
    if(pos == 0):
        return int(DeleteDigit(str(N)[1:],pos-1))
    else:
        return int(str(N)[0] + str(DeleteDigit(str(N)[1:],pos-1)))

print(DeleteDigit(int(input("Enter the integer : ")),int(input("Enter the position to remove : "))))