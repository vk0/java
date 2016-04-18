# -*- coding: utf-8 -*-
# There is a horizontal row of nn cubes. The length of each cube is given. You need to create a new vertical pile of cubes. The new pile should follow these directions: if cubeicubei is on top of cubejcubej then sideLengthj≥sideLengthisideLengthj≥sideLengthi.

# When stacking the cubes, you can only pick up either the leftmost or the rightmost cube each time. Print "Yes" if it is possible to stack the cubes. Otherwise, print "No". Do not print the quotation marks.

# Input Format

# The first line contains a single integer TT, the number of test cases.
# For each test case, there are 22 lines.
# The first line of each test case contains nn, the number of cubes.
# The second line contains nn space separated integers, denoting the sideLengths of each cube in that order.

# Constraints
# 1≤T≤51≤T≤5
# 1≤n≤1051≤n≤105
# 1≤sideLength<2311≤sideLength<231
# Output Format

# For each test case, output a single line containing either "Yes" or "No" without the quotes.

# Sample Input

# 2
# 6
# 4 3 2 1 3 4
# 3
# 1 3 2
# Sample Output

# Yes
# No
# Explanation

# In the first test case, pick in this order: left - 44, right - 44, left - 33, right - 33, left - 22, right - 11.
# In the second test case, no order gives an appropriate arrangement of vertical cubes. 33 will always come after either 11 or 22.

from collections import deque
for _ in range(int(input())):
    n = int(input())
    d = deque(list(map(int, input().split())))
    if d[0] > d[-1]: cur = d.popleft()
    else: cur = d.pop()
    while(len(d) > 0):
        if d[0] >= d[-1] and d[0] <= cur:
            cur = d.popleft()
        elif d[-1] >= d[0] and d[1] <= cur:
            cur = d.pop()
        else:
            break
    print("Yes" if len(d) == 0 else "No")