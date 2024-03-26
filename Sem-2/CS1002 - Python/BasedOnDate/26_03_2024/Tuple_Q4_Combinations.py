def Comb(l):
    return [(a,b,c,d) for a in l for b in l for c in l for d in l if (a*b==c*d and a!=b and a!=c and a!=d and b!=c and b!=d and c!=d)]





print(Comb(eval(input("Enter a list of elements : "))))