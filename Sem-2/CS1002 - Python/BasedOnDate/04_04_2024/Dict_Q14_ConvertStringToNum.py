import re
d = eval(input("Enter the dictionary: "))
exp = "[0-9]+\.?[0-9]*"
for i in d:
    if(d[i] in re.findall(exp,d[i])):
        d[i] = float(d[i])
print(d)