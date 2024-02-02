N = int(input("Enter the End of Series : "))
for i in range(1,N+1):
    c = 0
    for j in range(i+1):
        c+=j
    print(c,end=" ")
