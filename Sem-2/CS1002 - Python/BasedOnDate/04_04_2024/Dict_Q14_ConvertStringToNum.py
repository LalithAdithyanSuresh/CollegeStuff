import re
d = eval(input("Enter the dictionary: "))
for i in d:
    if(d[i] in re.findall("[0-9]+\.?[0-9]*",d[i])):
        d[i] = float(d[i])
print(d)