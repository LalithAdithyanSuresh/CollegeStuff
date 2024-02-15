# Generate a caesar's Cipher
print(ord('a'),ord('z'))
MainString = list(input("Enter the String : "))
N = int(input("Enter Code to rotate Characters : "))
for i in range(len(MainString)):
    Code = ord(MainString)+N
    
    MainString[i] = chr(ord(MainString)+N)