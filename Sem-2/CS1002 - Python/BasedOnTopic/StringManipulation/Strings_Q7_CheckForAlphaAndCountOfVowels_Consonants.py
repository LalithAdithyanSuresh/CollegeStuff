# Program to check if the string countains only alphabets and to find number of vowels and consonants

String = input("Enter the string : ")
Vow = Con = 0
if String.isalpha():
    for i in String:
        if i in 'aeiou':
            Vow+=1
        else:
            Con+=1

print("Vowels : " + str(Vow),"Consonants : " + str(Con),sep="\n")