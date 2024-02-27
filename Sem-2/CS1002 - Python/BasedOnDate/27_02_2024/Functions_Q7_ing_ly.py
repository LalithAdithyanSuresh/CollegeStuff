def inglyAdder(Sentence):
    if(len(Sentence)>3):
        if(Sentence[-3:] == 'ing'):
            return Sentence+'ly'
        else:
            return Sentence+'ing'
    else:
        return Sentence
    
N = input("Enter the String : ")
print(inglyAdder(N))