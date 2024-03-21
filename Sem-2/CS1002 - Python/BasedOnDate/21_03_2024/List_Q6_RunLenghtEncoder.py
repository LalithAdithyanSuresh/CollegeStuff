# Create a py scrip to create a run time encoder

ini = eval('['+input("Enter the list seperated by commas : ") + ']')
out = []
c = 0
for i in range(len(ini)-1):
    if(ini[i]==ini[i+1]):
        c+=1
    else:
        if(c == 0):
            out.append(ini[i])
            c = 0
        else:
            out.append([ini[i],c+1])
            c = 0
if(c!=0):
    out.append([ini[-1],c+1])
else:
    out.append(ini[-1])
print(out)
