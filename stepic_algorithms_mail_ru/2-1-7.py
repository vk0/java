# Реализуйте дек с динамическим зацикленным буфером.
# Для тестирования дека на вход подаются команды.
# В первой строке количество команд. Затем в каждой строке записана одна команда.

# Каждая команда задаётся как 2 целых числа: a b.

# a = 1 - push front,

# a = 2 - pop front,

# a = 3 - push back,

# a = 4 - pop back.

# Если дана команда pop*, то число b - ожидаемое значение. Если команда pop вызвана для пустой структуры данных, то ожидается “-1”.

# Требуется напечатать YES, если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

# Sample Input:

# 5
# 1 44
# 3 50
# 2 44
# 2 50
# 2 -1

# Sample Output:

# YES

from collections import deque

PUSH_FRONT, POP_FRONT, PUSH_BACK, POP_BACK = range(1, 5)

def process_commands(commands):
    d = deque()
    for command in commands:

        if command[0] == PUSH_FRONT:
            d.append(command[1])

        elif command[0] == POP_FRONT:
            if len(d) == 0 and command[1] == -1:
                return True
            if len(d) == 0 and command[1] != -1:
                return False
            el = d.pop()
            if el != command[1]:
                return False

        elif command[0] == PUSH_BACK:
            d.appendleft(command[1])

        elif command[0] == POP_BACK:
            if len(d) == 0 and command[1] == -1:
                return True
            if len(d) == 0 and command[1] != -1:
                return False
            el = d.popleft()
            if el != command[1]:
                return False
    return True

def main():
    command_count = int(input())
    # command_count = 5
    commands = []

    for i in range(command_count):
        command_list = input().split()
        command_list = list(map(int, command_list))
        commands.append(command_list)
    #commands = [[1, 44], [3, 50], [2, 44], [2, 50], [2, -1]]

    if not process_commands(commands):
        print("NO")
    else:
        print("YES")

if __name__ == "__main__":
    main()