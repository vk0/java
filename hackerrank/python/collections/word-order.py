# -*- coding: utf-8 -*-
# You are given nn words. Some words may repeat. For each word, output its number of occurrences. The output order should correspond with the input order of appearance of the word. See the sample input/output for clarification.

# Note: Each input line ends with a "\n" character.

# Constraints:
# 1≤n≤1051≤n≤105
# The sum of the lengths of all the words do not exceed 106106
# All the words are composed of lowercase English letters only.

# Input Format

# The first line contains the integer, nn.
# The next nn lines each contain a word.

# Output Format

# Output 22 lines.
# On the first line, output the number of distinct words from the input.
# On the second line, output the number of occurrences for each distinct word according to their appearance in the input.

# Sample Input

# 4
# bcdef
# abcdefg
# bcde
# bcdef
# Sample Output

# 3
# 2 1 1
# Explanation

# There are 33 distinct words. Here, "bcdef" appears twice in the input at the first and last positions. The other words appear once each. The order of the first appearances are "bcdef", "abcdefg" and "bcde" which corresponds to the output.

from collections import OrderedDict
dct = OrderedDict()
for _ in range(int(input())):
    i = input()
    dct[i] = dct.get(i, 0) + 1
print(len(dct))
for w in dct.values():
    print(w, end=' ')