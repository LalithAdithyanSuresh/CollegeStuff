def Armstrong(num):
    if(num == sum([int(x)**len(str(num)) for x in str(num)])):
        return True
    return False

def Deficient(num):
    if(num > sum([int(x) for x in range(1,num) if(num%int(x)==0)] )):
        return True
    return False
def Palindrome(num):
    if(str(num) == str(num)[::-1]):
        return True
    return False


while True:
    c = int(input("\nEnter the option:\n\t1-Armstrong\n\t2-Deficient\n\t3-Palindrome\n\t4-Exit\n>>> "))
    if(0<c<4):N = int(input("\nEnter the number : "))
    if(c == 1):
        if(Armstrong(N)):
            print("The given number is an armstrong number")
        else:
            print("The number is not an armstrong number")
    elif(c== 2):
        if(Deficient(N)):
            print("the number is a deficient number")
        else:
            print("The Number is not deficient")
    elif(c==3):
        if(Palindrome(N)):
            print("The number is a palindrome")
        else:
            print("The number is not a palindrome")
    elif(c==4):
        print("Exiting program")
        break
    else:
        print("Wrong Option")