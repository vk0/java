X=int(input())
H=int(input())
M=int(input())

hr=(H+(X//60)) #8
mn=(M+(X%60)) #110
if mn > 60:
    hr = hr+(mn//60)
    mn = mn - 60
    print(hr)
    print(mn)
else:
    if mn < 60:
        print(hr)
        print(mn)