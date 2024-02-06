marks = [int(input("Enter Mark for Maths :")),int(input("Enter Mark for Physics :")),int(input("Enter Mark for Chemistry :")),int(input("Enter Mark for Computer Science :")),int(input("Enter Mark for English :"))]
averagemarks = 0
for i in marks:
    averagemarks+=i
averagemarks/=5
if(averagemarks >90):
    print("Grade : A+")
elif(averagemarks >80):
    print("Grade : A")
elif(averagemarks >70):
    print("Grade : B+")
elif(averagemarks >60):
    print("Grade : B")
elif(averagemarks >50):
    print("Grade : C")
elif(averagemarks >40):
    print("Grade : D")
else:
    print("Grade : F")
