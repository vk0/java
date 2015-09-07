def modify_list(l):
    b = []
    for i in l:
        if i%2 == 0:
            b.append(int(i/2))
    l[:] = b