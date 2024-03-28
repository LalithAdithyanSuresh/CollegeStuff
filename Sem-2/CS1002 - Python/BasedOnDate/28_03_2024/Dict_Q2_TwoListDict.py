l1 = eval(input("List 1 : "))
l2 = eval(input("List 2 : "))
d1 = {i:j for (i,j) in zip(l1,l2)}
print(d1)