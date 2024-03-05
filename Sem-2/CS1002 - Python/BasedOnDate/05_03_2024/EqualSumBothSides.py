# Program to find the index value at wich sum on both sides of it are equal

l = [1,2,3,4,6,9,1]
for i in range(len(l)-1):
    if(sum(l[:i]) == sum(l[i+1:])):
        print("yes, element : {} at index : {}".format(l[i],i))
        exit()
print("No element found")