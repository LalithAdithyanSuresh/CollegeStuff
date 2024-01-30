# Bin,Decimal,Hexasecimal,Octal conversions and logical operations

a = int(input('Enter the value for a : '))
b = int(input('Enter the value for b : '))

print("To Binary\n\ta = {}\n\tb = {}".format(bin(a),bin(b)))
print("To Octal\n\ta = {}\n\tb = {}".format(oct(a),oct(b)))
print("To Hexa\n\ta = {}\n\tb = {}".format(hex(a),hex(b)))
print("And operation :\n\tIn decimal : {}\n\tIn Binary : {}".format(a and b , bin(a and b)))
print("OR operation :\n\tIn decimal : {}\n\tIn Binary : {}".format(a or b , bin(a or b)))
print("Not operation :\n\tFor a : \n\t\tIn decimal : {}\n\t\tIn Binary : {}\n\tFor b : \n\t\tIn decimal : {}\n\t\tIn Binary : {}".format(not a , bin(not a),not b, bin(not b)))
print("Left Shift operation :\n\tIn decimal : {}\n\tIn Binary : {}".format(a << b ,bin(a<<b)))
print("Right Shift operation :\n\tIn decimal : {}\n\tIn Binary : {}".format(a>> b ,bin(a>>b)))

