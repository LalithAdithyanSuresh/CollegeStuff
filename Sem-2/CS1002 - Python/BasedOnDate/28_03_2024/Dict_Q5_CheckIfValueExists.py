d1 = {1:10,2:20,3:30}
n = int(input("Enter the value to check for : "))
for i in d1:
    if d1[i]==n:
        print("The value exists in the dictionary under the key : ",i)
        exit()
print("No such value exists")