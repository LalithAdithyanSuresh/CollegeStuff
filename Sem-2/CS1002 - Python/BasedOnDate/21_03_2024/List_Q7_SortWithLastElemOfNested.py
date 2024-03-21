# Get a nested list form the user and sort the main list with respect to the last element of each list

ini = eval('['+input("Enter the nested lists : ")+']')
for i in range(len(ini)):
    for j in range( i,len(ini)-i):
        if(ini[j][-1] < ini[i][-1]):
            ini[j],ini[i] = ini[i],ini[j]
print(ini)