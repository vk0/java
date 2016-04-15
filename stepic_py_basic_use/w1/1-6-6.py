# Рассмотрим следующее объявление классов

class A:
    pass

class B(A):
    pass

class C:
    pass

class D(C):
    pass

class E(B, C, D):
    pass


# Какие последовательности могут являться корректным порядком разрешения методов для класса E?
E, B, C, D, A, object
E, B, A, C, D, object
E, B, D, C, A, object
E, B, A, D, C, object
*Никакие из перечисленных