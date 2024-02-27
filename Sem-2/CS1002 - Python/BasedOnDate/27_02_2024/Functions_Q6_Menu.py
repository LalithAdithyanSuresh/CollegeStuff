def ReverseWords(Sentence):
    return " ".join([x for x in Sentence.split(' ')[::-1]])
def CharInString(Sentence):
    unique = ''
    for x in Sentence:
        if x not in unique:
            unique+=x
    return unique
def Counts(Sentence):
    Chars={}
    for x in Sentence:
        if x in Chars:
            Chars[x] +=1
        else:
            Chars[x] = 1
    return len(Sentence.split(' ')) , Chars

def SubString(Sentence,SubS = 'ing'):
    return SubS in Sentence

def Encode(Sentence):
    i = 0
    while True:
        if(i+3>= len(Sentence)):
            return Sentence
        Sentence = Sentence[:i] +Sentence[i+1] + Sentence[i] + Sentence[i+2:]
        i+=1
        Sentence = Sentence[:i] +Sentence[i+2] +Sentence[i+1]+ Sentence[i] + Sentence[i+3:]
        i+=1


while True:
    opt = int(input("Enter your Option\n\t1 - Reverse Words\n\t2 - Chars In String\n\t3 - Counts\n\t4 - String In String\n\t5 - Encode\n\t6 - Exit\n>>> "))
    String = input("Enter the String : ")
    if(opt == 1):
        print(ReverseWords(String))
    elif(opt == 2):
        print(CharInString(String))
    elif(opt == 3):
        a,b = Counts(String)
        print("Number of words = ",a)
        for i,j in b.items():
            print("\t{} - {}".format(i,j))
    elif(opt ==4):
        s = input("Enter the Substring to search for : ")
        if(SubString(String,s)):
            print("Found Substring")
        else:
            print("Substring not found")

    elif(opt == 5):
        print(Encode(String))
    elif(opt == 6):
        break