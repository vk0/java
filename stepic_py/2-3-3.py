A=int(input())
B=int(input())
C=int(input())
D=int(input())
for j in range(C,D+1):
    print("\t" + str(j), end="")
print()

for i in range(A,B+1):
    print(i, end="")
    for j in range(C,D+1):
        print("\t" + str(i*j), end="")
    print()