import sys
args = sys.argv
if len(args)!=2:
    exit()

for i in range(2,args[1]):
    for j in range(3,i//2):
        if