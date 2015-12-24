# Напишите программу, которая реализует mapper для задачи WordCount в Hadoop Streaming.

# Sample Input:

# Vivere est cogitare
# Vivere militate est
# Scientia potentia est

# Sample Output:

# Vivere  1
# est 1
# cogitare    1
# Vivere  1
# militate    1
# est 1
# Scientia    1
# potentia    1
# est 1

import sys

for line in sys.stdin:
    for token in line.strip().split(" "):
        if token:
            print(token + '\t1')