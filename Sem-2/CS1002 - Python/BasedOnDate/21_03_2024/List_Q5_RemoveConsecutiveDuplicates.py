# A program to remove all consecutive duplicates

ini = eval('[' + input("Enter list seperated by commas : " )+ ']')
out = []
for i in range(len(ini)-1):
    if(ini[i] != ini[i+1]):
        out.append(ini[i])
out.append(ini[-1])
print(out)