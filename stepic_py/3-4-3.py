wordcount={}
c = 0
x = ''
with open('dataset_3363_3.txt') as inf:
    for line in inf:
        line = line.strip()
        for word in line.lower().split():
            if word not in wordcount:
                wordcount[word] = 1
            else:
                wordcount[word] += 1
for k,v in sorted(wordcount.items()):
    if v > c:
        c = v
        x = k
print(x, c)