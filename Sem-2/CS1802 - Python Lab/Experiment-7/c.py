# Menu driven program for recursive functions

def Fibonacci(n,s1=0,s2=1):
    if(n==0):
        return 
    else:
        print(s2,end=', ')
        Fibonacci(n-1,s2,s1+s2)
def AP(start,diff,n,c=0):
    if(n==c):
        return
    else:
        print(start + c*diff,end=', ')
        AP(start,diff,n,c+1)
def GP(start,ratio,n,c=0):
    if(n==c):
        return
    else:
        print(start * ratio**c,end=', ')
        GP(start,ratio,n,c+1)
def HP(start,diff,n,c=0):
    if(n==c):
        return
    else:
        print('{:.3f}'.format(1/(start + c*diff)),end=', ')
        HP(start,diff,n,c+1)
def TSeries(n,t=1,o=0):
    if(t==n+1):
        return
    else:
        print(o+t,end=', ')
        TSeries(n,t+1,o+t)

opt = 1
while(opt!=0):
    opt = int(input("\nOptions :\n\t1-Fibonacci\n\t2-AP\n\t3-GP\n\t4-HP\n\t5-T Seties\n\t0-EXIT\n>>>"))
    if(opt == 1):
        Fibonacci(int(input("Enter the number of terms : ")))
    elif(opt == 2):
        AP(int(input("Enter the Start number : ")),int(input("Enter the Diff : ")),int(input("Number of terms : ")))
    elif(opt==3):
        GP(int(input("Enter the Start number : ")),int(input("Enter the Ratio : ")),int(input("Number of terms : ")))
    elif(opt==4):
        HP(int(input("Enter the Start number : ")),int(input("Enter the Diff : ")),int(input("Number of terms : ")))
    elif(opt==5):
        TSeries(int(input("Enter the number of terms : ")))
    else:
        break
    print()

