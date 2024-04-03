N = int(input("Enter the number of items : "))
Prices = {}
for i in range(1,N+1):
    print("Enter Details of Item - ",i)
    Prices[input("\tName : ")] = int(input("\tPrice : "))

PricesInOrder = sorted(list(Prices.values()),reverse=True)
k = int(input("Enter the value of  K : "))
c = 0
for i in PricesInOrder[:k]:
    c+=1
    for j in Prices:
        if Prices[j] == i:
            print(c," - ",j)