X=int(input())
if (not X % 4 and X % 100) or not X % 400:
    print("Високосный")
else:
    print("Обычный")