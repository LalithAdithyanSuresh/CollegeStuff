# Given a string verify if it is a valid email-id
import re
mail = input()
b = re.search('^[A-Za-z\.-_][A-Za-z\.-_0-9]+[@][a-z-_]{2,}[\.][a-z]+$',mail)
print(b.group())