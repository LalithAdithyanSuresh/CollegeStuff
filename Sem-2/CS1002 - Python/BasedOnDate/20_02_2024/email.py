import re

email = input("Enter the email : ")
check = re.findall('[A-Za-z]+@[A-Za-z]+\.[A-Za-z]+',email)
print(check)