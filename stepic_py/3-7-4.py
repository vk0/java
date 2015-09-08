n = int(input())
pos = [0,0]
for i in range(n):
    cmd = input()
    ls = cmd.split()
    if ls[0] == "север":
        pos[1] += int(ls[1])
    elif ls[0] == "запад":
        pos[0] -= int(ls[1])
    elif ls[0] == "юг":
        pos[1] -= int(ls[1])
    elif ls[0] == "восток":
        pos[0] += int(ls[1])

print(pos[0],pos[1])