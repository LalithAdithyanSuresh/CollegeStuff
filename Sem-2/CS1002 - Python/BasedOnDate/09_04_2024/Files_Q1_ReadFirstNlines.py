import sys
arg = sys.argv
if(len(arg) !=2):
    print("No arguments were given")
    exit()

file = open(arg[1])

n = int(input("Enter number of lines to read : "))
k = int(input("Enter number of character to omit : "))
print()
for i in range(n):
    print(file.readline().rstrip())
file.read(k)
print(file.read())