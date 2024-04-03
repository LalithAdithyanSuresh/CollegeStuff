# Remove duplicate value along with its keys from the dictionary 

ori = eval(input("Ente the Dictionary : "))
c = 0
values = list(ori.values())
new = {}
for i in ori:
    if values.count(ori[i])>1:
        values.remove(ori[i])
    else:
        new[i] = ori[i]
print(new)
