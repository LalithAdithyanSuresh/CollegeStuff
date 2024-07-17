n1 = input("Enter First Name : ")
n2 = input("Enter Second Name : ")
count = len(set(list(n1)+list(n2)))
text = list("FLAMES")
i = 1
while len(text)!=1:
    print(text)
    if(i%count==0):
        print(text[0])
        text.pop(0)
    text = text[1:] + [text[0]]
    i+=1
print(text)