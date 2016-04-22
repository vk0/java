# Реализуйте метод vectorized_forward_pass класса Perceptron. Когда вы начнёте решать задачу, вам нужно будет просто скопировать соответствующую функцию, которую вы написали в ноутбуке (без учёта отступов; шаблон в поле ввода ответа уже будет, ориентируйтесь по нему). Сигнатура функции указана в ноутбуке, она остаётся неизменной.

# n — количество примеров, m — количество входов. Размерность входных данных input_matrix — (n, m), размерность вектора весов — (m, 1), смещение (bias) — отдельно. vectorized_forward_pass должен возвращать массив формы (n, 1), состоящий либо из 0 и 1, либо из True и False.

# Обратите внимание, необходимо векторизованное решение, то есть без циклов и операторов ветвления. Используйте свойства умножения матриц и возможность эффективно применять какую-нибудь операцию к каждому элементу np.array, чтобы с минимумом кода получить желаемый результат. Например,

# >>> my_vec = np.array([-1, 2, 3])
# >>> is_positive = my_vec > 0
# >>> is_positive
# array([False,  True,  True], dtype=bool)

import numpy as np

def vectorized_forward_pass(self, input_matrix):
    n = input_matrix.shape[0]
    m = input_matrix.shape[1]
    b = np.array([self.b])
    w = np.vstack((b, self.w))
    ones = np.ndarray((n, 1),buffer=np.ones(n), dtype=float)
    x = np.hstack((ones, input_matrix))
    res = x.dot(w)
    bool_res = res > 0
    return bool_res