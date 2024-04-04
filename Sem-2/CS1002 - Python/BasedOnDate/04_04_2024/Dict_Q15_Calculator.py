a = int(input("Enter the First Number : "))
b = int(input("Enter the Next Number : "))
Opt = input("Enter operation : ")
Operations = {'+':a+b,'-':a-b,'*':a*b,'/':a/b}
print("Answer : ",Operations[Opt])