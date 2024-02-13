# Newton Method for finding Root
N = int(input("Enter the number to find root of : "))
l = float(input('Enter the tolerance level : '))
X = N
while(True):
    root = 0.5 * (X + (N/X))
    if(root - X<0):
        if(X-root< l):
            break
    else:
        if(root-X<l):
            break
    X = root
print(root)