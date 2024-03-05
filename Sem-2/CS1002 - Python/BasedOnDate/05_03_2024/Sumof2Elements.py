# A porgram to find two elements where their sum is equal to the user input

N = [20,30,50,70,20,10,80]
M = int(input("How much money do you have : "))
for i in range(len(N)-1):
    for j in range(i,len(N)):
        if(N[i] + N[j] == M):
            print("Found combination : {} and {}".format(N[i],N[j]))
            exit()
print("No such Combination exists")