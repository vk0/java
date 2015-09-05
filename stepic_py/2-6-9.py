a = [int(i) for i in input().split()]
b = int(input())
for i,l in enumerate(a):
    if b not in a:
        print("Отсутствует")
        break
    elif b == l:
        print(i,end=' ')
print()