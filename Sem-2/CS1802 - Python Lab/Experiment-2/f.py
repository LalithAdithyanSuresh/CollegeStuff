# Finding roots of quadratic equaion
import cmath,math

a = float(input("Enter the value of A : "))
b = float(input("Enter the value of B : "))
c = float(input("Enter the value of C : "))
det = math.pow(b,2) - (4 * a * c)
prev = -b / (2*a)
print("The roots are : {} and {}".format(prev + cmath.sqrt(det)/(2*a),prev + cmath.sqrt(det)/(2*a)))

