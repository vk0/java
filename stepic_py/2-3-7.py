A=int(input())
B=int(input())
list=[]
for j in range(A,B+1):
    if j % 3 == 0:
        list.append(j)
print(sum(list) / len(list))