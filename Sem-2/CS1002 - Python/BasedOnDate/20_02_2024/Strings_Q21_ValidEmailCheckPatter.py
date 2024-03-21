# Given a string verify if it is a valid email-id
import re
mail = input()
b = re.search('^[A-Za-z\.-_][A-Za-z\.-_0-9]+[@][a-z-_]{2,}[\.][a-z\.]+$',mail)
print(b.group())

pattern = "^((0|([1-9][0-9]?))|(1[0-9]{2})|(2[0-4][0-9])|(25[0-5]))\.){3}((0|([1-9][0-9]?))|(1[0-9]{2})|(2[0-4][0-9])|(25[0-5]))$"