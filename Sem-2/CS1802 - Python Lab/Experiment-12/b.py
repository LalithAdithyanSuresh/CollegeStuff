import sys
args = sys.argv
if len(args)!=2:
    exit()
try:
    f = open(args[1])
    print(f.read())
    f.close()
except:
    f = open(args[1],'w')
    content = input("Enter random content : ")
    f.write(content)
    f.close()