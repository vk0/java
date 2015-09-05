list=[]
list2=[]
while True:
    try:
        a=input()
        list.append(int(a))
        if sum(list) == 0:
            for i in list:
                list2.append(i**2)
            print(int(sum(list2)))
            break
    except EOFError:
        break