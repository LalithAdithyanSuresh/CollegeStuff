# Caeser's Cipher | rotate characters own the alphabet for n times to get an encrypted messqage

M_String = input("Enter the String : ")
N = int(input("Enter the Rotate Code : "))
E_String = ''
for letter in M_String:
    if(ord(letter.lower())+N > ord('z')):
        N_letter = chr(ord('a')-1+ (ord(letter.lower())+N)-ord('z'))
    elif(ord(letter.lower())+N > ord('a')):
        N_letter = chr(ord(letter.lower())+N)
    else:
        E_String += letter
        continue
    if letter.isupper():
        E_String +=N_letter.upper()
        continue
    E_String+=N_letter
print(E_String)