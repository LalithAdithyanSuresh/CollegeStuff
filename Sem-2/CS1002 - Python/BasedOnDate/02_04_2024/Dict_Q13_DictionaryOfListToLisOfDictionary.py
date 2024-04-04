# Conver the Dictionary containg list into lists containg dictionaries

ori = eval(input("Enter the Dictionary : "))
out = []
for i in range(len(ori[list(ori.keys())[0]])):
    temp = {}
    for j in ori:
        temp[j] = ori[j][i]
    out.append(temp.copy())
print(out)