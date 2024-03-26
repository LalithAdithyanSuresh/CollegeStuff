n = int(input("Numer of students : "))
l = [tuple([input("\tname: "),int(input('\tMarks: '))]) for x in range(n)]
marks =sorted(set([stud[1] for stud in l]),reverse=True)
k = int(input("\nEnter the value of k : "))
print("The student with the kth mark is : ",end='')
for i in l:
    if i[1] == marks[k-1]:
        print(i[0],end=', ')
print()
        