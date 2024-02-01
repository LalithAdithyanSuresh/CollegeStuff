# Find the sum of hte series to N terms
# x - x^3 + x^5 ...


N = int(input("Enter the number of terms : "))
x = int(input("Enter the value of x : "))
poly = 0
for i in range(1,N+1):
    poly -=  (-1)**(i)* (x**((2*i)-1))
print(poly)