# Реализуйте методы activation и summatory класса Neuron. Когда вы начнёте решать задачу, вам нужно будет просто скопировать соответствующую функцию, которую вы написали в ноутбуке (без учёта отступов; шаблон в поле ввода ответа уже будет, ориентируйтесь по нему). Сигнатура функции указана в ноутбуке, она остаётся неизменной.

# n — количество примеров, m — количество входов. Размерность входных данных input_matrix — (n, m), размерность вектора весов — (m, 1). vectorized_forward_pass должен возвращать массив формы (n, 1), состоящий из чисел (float). Мы будем проверять именно правильность ответа, который возвращает vectorized_forward_pass.

import numpy as np

def summatory(self, input_matrix):
    return input_matrix.dot(self.w)

def activation(self, summatory_activation):
    return self.activation_function(summatory_activation)

def vectorized_forward_pass(self, input_matrix):
    return self.activation(self.summatory(input_matrix))