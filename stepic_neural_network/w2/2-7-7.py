# Реализуйте функцию compute_grad_numerically_2, которая вычисляет градиент целевой функции по определению, «отступая» в две стороны одновременно: ∇J(w1,…,wm)=J(w1,…,wi+Δw,…,wm)−J(w1,…,wi−Δw,…,wm)2⋅Δw . Когда вы начнёте решать задачу, вам нужно будет просто скопировать соответствующую функцию, которую вы написали в ноутбуке (без учёта отступов; шаблон в поле ввода ответа уже будет, ориентируйтесь по нему). Сигнатура функции указана в ноутбуке, она остаётся неизменной.

import numpy as np

def compute_grad_numerically_2(neuron, X, y, J=J_quadratic, eps=10e-2):
    w_len = len(neuron.w)
    num_grad = np.zeros(neuron.w.shape)
    for i in range(w_len):
        old_wi = neuron.w[i][0]
        neuron.w[i] = old_wi + eps
        plus_delta = J(neuron, X, y)
        neuron.w[i] = old_wi - eps
        minus_delta = J(neuron, X, y)
        neuron.w[i][0] = old_wi
        num_grad[i][0] = (plus_delta - minus_delta) / (2 * eps)
    return num_grad