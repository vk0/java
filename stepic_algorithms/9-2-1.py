# Практика на Python: Расстояние редактирования

import random

def edit_distance(s1, s2):
    return 0

def main():
    s1 = input()
    s2 = input()
    print(edit_distance(s1,s2))

def test(n_iter=100):
    for i in range(n_iter):
        length = random.randint(0, 64)
        s = "".join(random.choice("01") for _ in range(length))

        assert edit_distance(s, "") == edit_distance("", s) == len(s)
        assert edit_distance(s, s) == 0
    assert edit_distance("ab","ab") == 0
    assert edit_distance("short","ports") == 3

if __name__ == '__main__':
    test()