# Sort the given string based on the frequency of every letter

s = input("Enter the string : ")
CharsFrequency = {}
for i in s:
    if i in CharsFrequency: CharsFrequency[i]+=1
    else:CharsFrequency[i] = 1
Chars = list(CharsFrequency.keys())
Freq = list(CharsFrequency.values())
for i in range(len(Freq)):
    for j in range(i,len(Freq)):
        if Freq[i]>Freq[j]:
            Freq[i],Freq[j],Chars[i],Chars[j] = Freq[j],Freq[i],Chars[j],Chars[i]
for j in range(len(Chars)):
    print(Chars[j]*Freq[j],end="")