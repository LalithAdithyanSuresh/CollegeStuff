# Recursive function to find the sum of elements inside a list

def FinsSumOfElem(L):
    if(len(L)==0):
        return 0
    else:
        return L.pop() + FinsSumOfElem(L)

print(FinsSumOfElem(eval(input("Enter a list with brackets and commas : "))))