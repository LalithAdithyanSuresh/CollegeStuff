def PTriplets(max):
    a = b = c = 0
    m = n = 1

    while(True):
        while(True): 
            m+=1
            a = m**2 - n**2
            b = 2*m*n
            c = m**2 + n**2
            if(a >max or b >max or c>max):
                break
            if(a<=0 or b<=0 or c<=0):
                continue
            print(a,b,c)
        m = 2
        n+=1
        a = m**2 - n**2
        b = 2*m*n
        c = m**2 + n**2
        if(a >max or b >max or c>max):
            break
        if(a<=0 or b<=0 or c<=0):
            continue
        print(a,b,c)



N = int(input("Enter max : "))
PTriplets(N)