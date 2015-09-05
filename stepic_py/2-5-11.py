a = [int(i) for i in input().split()]
list=[]
for i in a:
    if a.count(i) > 1:
        if i not in list:
            list.append(i)
print(' '.join(map(str, list)))