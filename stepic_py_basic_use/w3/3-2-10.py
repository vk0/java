# # -*- coding: utf-8 -*-
# Вам дана последовательность строк.
# Выведите строки, содержащие обратный слеш "\﻿".

# Sample Input:

# \w denotes word character
# No slashes here

# Sample Output:

# \w denotes word character

import sys
import re

pattern = r'\\'

for line in sys.stdin:
    line = line.rstrip()
    if re.findall(pattern, line):
        print(line)