opt = 1
while True:
    a = float(input("Enter Operand a : "))
    b = float(input("Enter Operand b : "))
    c = input("Arithmetic Operation (+ , - , * , /) : ")
    if(c=="+"):
        print(a,c,b , " = " ,a+b)
    elif(c=="-"):
        print(a,c,b , " = " ,a-b)
    elif(c=="*"):
        print(a,c,b , " = " ,a*b)
    else:
        print(a,c,b," = ",a/b)

    opt= int(input("Enter (1)  if you want to continue : "))
    if opt!=1:
        break
