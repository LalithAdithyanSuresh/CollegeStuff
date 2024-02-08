# Print the occurences of Uppercase , lowercase,digits,special chracters

s = input("Enter the string : ")
Counts = {'UpperCases' : 0, 'LowerCases':0, 'Digits':0,'SpecialChar':0}
print()
for i in s:
    if i.isupper() : Counts['UpperCases']+=1
    elif i.islower(): Counts['LowerCases']+=1
    elif i.isdigit(): Counts['Digits']+=1
    else: Counts['SpecialChar']+=1
for i,j in Counts.items():
    print(i," : ",j)