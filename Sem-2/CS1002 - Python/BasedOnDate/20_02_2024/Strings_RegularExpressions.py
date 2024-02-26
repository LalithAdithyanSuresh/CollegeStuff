# Using module re

import re

m = re.findall('^[A-Za-z][A-Za-z \.]','Lalith Adithyan S')
print(m)


email = re.findall('[A-Za-Z]@[A-Za-Z]+@gmail\.com','lalithadithyansuresh@gmail.com')
# print(email)
con ='^[A-Za-z][0-9]{3}[_][A-Za-z]{2,}'

pattern = re.findall('^[A-Za-z][0-9]{3}[_][A-Za-z]{2,}','A424_iwffs5')
pattern1 = re.match(con,'A424_iwffs5')

b = re.search('^[A-Za-z][0-9]{3}[_][A-Za-z]{2,}','A424_iwffs5')
print(pattern)
print(pattern1,b.group())