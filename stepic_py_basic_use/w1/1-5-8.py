# Реализуйте класс MoneyBox, для работы с виртуальной копилкой.

# Каждая копилка имеет ограниченную вместимость, которая выражается целым числом – количеством монет, которые можно положить в копилку. Класс должен поддерживать информацию о количестве монет в копилке, предоставлять возможность добавлять монеты в копилку и узнавать, можно ли добавить в копилку ещё какое-то количество монет, не превышая ее вместимость.

# Класс должен иметь следующий вид

# class MoneyBox:
#     def __init__(self, capacity):
#         # конструктор с аргументом – вместимость копилки

#     def can_add(self, v):
#         # True, если можно добавить v монет, False иначе

#     def add(self, v):
#         # положить v монет в копилку

# При создании копилки, число монет в ней равно 0.

# Примечание:
# Гарантируется, что метод add(self, v) будет вызываться только если can_add(self, v) – True﻿.

class MoneyBox:
    def __init__(self, capacity):
        # конструктор с аргументом – вместимость копилки
        self.capacity = capacity
        self.total = 0

    def can_add(self, v):
        # True, если можно добавить v монет, False иначе
        self.canadd = v
        if self.total + self.canadd > self.capacity:
            return False
        else:
            return True

    def add(self, v):
        # положить v монет в копилку
        self.addn = v
        if self.can_add(v):
            self.total += self.addn

c = int(20)
m=MoneyBox(c)
m.add(10)
print(m.can_add(20))