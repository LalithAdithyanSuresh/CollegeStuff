# Using module re

import re

m = re.findall('^[A-Za-z][A-Za-z \.]{3}','Lalith Adithyan S')
print(m)


# email = re.findall('[A-Za-Z]@[A-Za-Z].\[A-Za-Z]','lalithadithyansuresh@gmail.com')
# print(email)


pattern = re.findall('^[A-Za-z][0-9]{3}[_][A-Za-z]{2,}$','A424_iwffs')
pattern1 = re.match('^[A-Za-z][0-9]{3}[_][A-Za-z]{2,}$','A424_iwffs')
print(type(pattern))
print(type(pattern1))
