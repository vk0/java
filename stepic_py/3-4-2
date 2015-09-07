import re
inf = open('dataset_3363_2.txt', 'r')
string = inf.readline().strip()
c = re.findall('[A-z]+',string)
n = re.findall('[0-9]+',string)
for i in range(len(c)):
    print(c[i] * int(n[i]),end='')