# -*- coding: utf-8 -*-
# Вам дается текстовый файл, содержащий некоторое количество непустых строк.
# На основе него сгенерируйте новый текстовый файл, содержащий те же строки в обратном порядке.

# Пример входного файла:
# ab
# c
# dde
# ff

# ﻿Пример выходного файла:
# ff
# dde
# c
# ab

filename = 'dataset_24465_4.txt'
filename_rev = 'dataset_24465_4-rev.txt'

with open(filename) as f,  open(filename_rev, 'w') as fout:
    fout.writelines(reversed(f.readlines()))