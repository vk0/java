a=input()
wordcount={}
for word in a.lower().split():
    if word not in wordcount:
        wordcount[word] = 1
    else:
        wordcount[word] += 1
for k,v in wordcount.items():
    print(k, v)