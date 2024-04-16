import os
import sys
import re

if(len(sys.argv) !=3):
    print("Invalid Number of arguments ")
    exit()
InputFolder , OutputFolder = sys.argv[1],sys.argv[2]

domain = "@snuchennai.edu.in"

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
            os.remove(OutputFolder)
        else:
            print("Program exiting")
            exit()
except:
    os.mkdir(OutputFolder)


for i in InputFiles:
    CurrFile = open(InputFolder+'/'+i)
    usernames = CurrFile.readlines()
    CurrFile.close()
    for i in usernames:
        
