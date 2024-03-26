# Print the binary equivalent of a number

def DecToBin(Dec):
    if(Dec == 0):
        return
    else:
        DecToBin(Dec//2)
        if(Dec%2==1):
            print('1',end='')
        else:
            print('0',end='')
DecToBin(int(input("Enter the Decimal Value : ")))
print()