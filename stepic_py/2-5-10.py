a = [int(i) for i in input().split()]
rng = len(a)
for i in range(rng):
    if rng == 1:
        print(a[0])
    elif i == rng-1:
        print(int(a[0]) + int(a[i-1]),end=" ")
    else:
        #print(a[i])
        print(int(a[i+1]) + int(a[i-1]),end=" ")