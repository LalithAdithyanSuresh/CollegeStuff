# Print Diamond Pattern

N = int(input("Enter the maximum number in the pattern : "))
for i in range(1,N+1):
    print("  "*(N-i),(str(i)+'   ')*i)
for i in range(N-1,0,-1):
    print("  "*(N-i),(str(i)+'   ')*i)
