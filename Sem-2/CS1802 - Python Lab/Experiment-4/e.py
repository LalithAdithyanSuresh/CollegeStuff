# Find the sum of series
sum = 0
N = int(input("Enter the number of terms in Series : "))
F_Series = [1,1]
for i in range(2,N):
    F_Series.append(F_Series[i-1] + F_Series[i-2])
for i in range(N):
    sum+= ((-1)**i) * (F_Series[i]**(i+1))
print("Sum of Series = ",sum)