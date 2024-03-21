# In a list of strings, find the strings that start with a letter given by the user

strings = eval('[' + input("Enter the strings : ") + ']')
char = input("Enter the character to search for : ")
print(' , '.join([i for i in strings if(i[0] == char)]))