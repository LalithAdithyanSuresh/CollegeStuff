import os
import sys
import re

if(len(sys.argv) !=3):
    print("Invalid Number of arguments ")
    exit()
InputFolder , OutputFolder = sys.argv[1],sys.argv[2]

domain = "@snuchennai.edu.in"
ptr = "^[A-Za-z][A-Za-z0-9\.-_]*$"

# Input Folder Check
try:
    InputFiles = os.listdir(InputFolder)
except:
    print("Input Folder Does not exist")
    exit()

# Output Folder Check
try:
    OutputFiles = os.listdir(OutputFolder)
    if(len(OutputFiles)>1):
        print("Files already exist in the Output Folder")
        if(input("\nDo you want to overwrite the folder's contents? (y/n)") == 'y'):
            os.rmdir(OutputFolder)
        else:
            print("Program exiting")
            exit()
except:
    os.mkdir(OutputFolder)


for i in InputFiles:
    CurrFile = open(InputFolder+'/'+i)
    usernames = CurrFile.readlines()
    CurrFile.close()
    for j in range(len(usernames)):
        user = usernames[j]
        if(user in re.findall(user,ptr)):
            pass
        else:
            user = list(user)
            valid = ''
            for k in range(len(user)):
                if(user[k].isalnum() or user[k]=='.' or user[k]=='_' or user[k]=='-'):
                    valid+=user[k]
                elif(user[k]=='@'):
                    break
                else:
                    continue
            user = valid
        user+=domain
        usernames[j]=user
    outFile = open(OutputFolder+'/'+i,'w')
    for i in usernames:
        outFile.write(i+'\n')
    outFile.close()
            
