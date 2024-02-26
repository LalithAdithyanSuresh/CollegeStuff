# Merging two string in Zipper form 

S1 = input("Enter the String - 1 : ")
S2 = input("Enter the String - 2 : ")
S3 = ''
while(not(S1 == '' and S2=='')):
    if(S1 == ''):
        S3 += S2[0]
        S2 = S2[1:]
    elif(S2 == ''):
        S3 += S1[0]
        S1 = S1[1:]
    else:
        S3 += S1[0] + S2[0]
        S1 = S1[1:]
        S2 = S2[1:]
print(S3)