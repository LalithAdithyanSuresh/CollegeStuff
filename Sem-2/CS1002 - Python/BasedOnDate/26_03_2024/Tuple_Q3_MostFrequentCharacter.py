def MFC(stri):
    hash = {}
    max = 0
    m = ''
    for i in stri:
        if i in hash:
            hash[i] +=1
        else:
            hash[i] = 1
        if hash[i] > max:
            max = hash[i]
            m = i
    return m,hash[m]

print(MFC(input("Enter the string : ")))
    