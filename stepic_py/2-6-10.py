z = []
while True:
    a = input()
    if a == "end":
        break
    else:
        z.append([int(i) for i in a.split()])
hor = len(z)
ver = len(z[0])
k = [[0 for i in range(ver)] for i in range(hor)]
if hor == 1 and ver == 1:
    print(int(z[0][0])*4)
elif hor == 1:
    print(z[0][ver-1]+z[0][1]+int(z[0][0])*2, end=" ")
    for i in range(1,ver-1):
        print(z[0][i-1]+z[0][i+1]+int(z[0][i])*2, end=" ")
    print(z[0][0]+z[0][ver-2]+int(z[0][ver-1])*2)
elif ver == 1:
    print(z[hor-1][0]+z[1][0]+int(z[0][0])*2)
    for i in range(1,hor-1):
        print(z[i-1][0]+z[i+1][0]+int(z[i][0])*2)
    print(z[0][0]+z[hor-2][0]+int(z[hor-1][0])*2)
else:
    for i in range (0,hor):
        for j in range (0,ver):
            if i == 0:
                if j == 0:
                    k[i][j] = z[1][0]+z[0][1]+z[0][ver-1]+z[hor-1][0]
                elif j == ver-1:
                    k[i][j] = z[i+1][j]+z[i][j-1]+z[i][0]+z[hor-1][j]
                else:
                    k[i][j] = z[i][j-1]+z[i][j+1]+z[hor-1][j]+z[i+1][j]
            elif j == 0:
                if i == hor-1:
                    k[i][j] = z[i-1][j]+z[i][j+1]+z[0][0]+z[hor-1][ver-1]
                else:
                    k[i][j] = z[i-1][j]+z[i+1][j]+z[i][j+1]+z[i][ver-1]
            elif j == ver-1:
                if i == hor-1:
                    k[i][j] = z[i-1][j]+z[i][j-1]+z[i][0]+z[0][j]
                else:
                    k[i][j] = z[i-1][j]+z[i+1][j]+z[i][j-1]+z[i][0]
            elif i == hor-1:
                k[i][j] = z[i-1][j]+z[i][j-1]+z[i][j+1]+z[0][j]
            else:
                k[i][j] = z[i][j-1]+z[i][j+1]+z[i-1][j]+z[i+1][j]
    for i in range (0,hor):
        for j in range (0,ver):
            print(k[i][j],end=" ")
        print()