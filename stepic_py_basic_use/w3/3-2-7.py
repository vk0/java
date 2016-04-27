# -*- coding: utf-8 -*-
# Вам дана последовательность строк.
# Выведите строки, содержащие "cat" в качестве подстроки два раза.

# Примечание:
# Считать все строки по одной из стандартного потока ввода вы можете, например, так

# import sys

# for line in sys.stdin:
#     line = line.rstrip()
#     # process line


# Sample Input:

# catcat
# cat and cat
# catac
# cat
# ccaatt

# Sample Output:

# catcat
# cat and cat

import sys

pattern = "cat"
for line in sys.stdin:
    line = line.rstrip()
    if line.count(pattern) >= 2:
        print(line)