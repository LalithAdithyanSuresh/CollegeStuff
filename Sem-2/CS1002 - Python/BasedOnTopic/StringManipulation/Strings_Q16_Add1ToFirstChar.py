# Every words first letter should be the next alphabet in the series.
sentence = list(' '+input("Enter the sentence : "))
for x in range(len(sentence)):
    if sentence[x].isspace():
        if sentence[x+1] not in 'Zz':
            sentence[x+1] = chr(ord(sentence[x+1])+1)
        else:
            sentence[x+1] = chr(ord(sentence[x+1])-25)
print(''.join(sentence).lstrip())