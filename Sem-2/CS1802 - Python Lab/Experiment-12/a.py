unigram_prob = {}
unigram_occur = {}
bigram_prob = {}
bigram_occur = {}

def UnigramProbCheck(Words):
    for word in Words:
        if word in unigram_occur:
            unigram_occur[word]+=1
        else:
            unigram_occur[word] =1
    for i in unigram_occur:
        unigram_prob[i] = unigram_occur[i] / len(Words)

def BigramProbCheck(Words):
    for i in range(len(Words)-1):
        comb = Words[i]+'_'+Words[i+1]
        if comb in bigram_occur:
            bigram_occur[comb] +=1
        else:
            bigram_occur[comb] = 1
    for i in bigram_occur:
        bigram_prob[i] = bigram_occur[i] / unigram_occur[i.split('_')[0]]
def CleanTexttoList(text):
    l = []
    for i in text.split():
        l.append(i.strip())
    return l
gram_file = open('GramFile.txt')
wordList = CleanTexttoList(gram_file.read())
UnigramProbCheck(wordList)
BigramProbCheck(wordList)

import sys
sentence = sys.argv[1:]
p=unigram_prob[sentence[0]]
for i in range(1,len(sentence)-1):
    try:
        p*=bigram_prob[sentence[i]+'_'+sentence[i+1]]
    except:
        p*=0.1
print(p)
