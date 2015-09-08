a=input()
b=input()
toencode=input()
todecode=input()
d = {k:v for k,v in zip(a,b)}
drev = {v:k for k,v in d.items()}
for c in toencode:
    print(d[c],end='')
print()
for c1 in todecode:
    print(drev[c1],end='')
print()