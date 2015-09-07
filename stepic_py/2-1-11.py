list=[]
while True:
    A=int(input())
    if A != 0:
        list.append(A)
    elif A == 0:
        if len(list) == 0:
            print("0")
            break
        else:
            print(sum(list))
            del list[:]
            break
    else:
        break
