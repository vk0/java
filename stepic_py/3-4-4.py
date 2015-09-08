with open ('dataset_3363_4.txt') as file:
    m = []
    f = []
    r = []
    for line in file:
        s1 = line.strip().split(';')
        m.append(int(s1[1]))
        f.append(int(s1[2]))
        r.append(int(s1[3]))
        print((int(s1[1]) + int(s1[2]) + int(s1[3]))/3)
    print(sum(m) / len(m), sum(f) / len(f), sum(r) / len(r))
    print()