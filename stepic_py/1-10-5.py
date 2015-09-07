A=int(input())
B=int(input())
H=int(input())

if A <= H and H <= B:
    print("Это нормально")
elif H > B:
    print("Пересып")
elif H < A:
    print("Недосып")