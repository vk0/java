a=int(input())
l=[]
for i in range(0,a):
    i+=1
    for j in range(0,i):
        l.append(i)
print(*l[:a], sep=" ")