# -*- coding: utf-8 -*-
# Mr. Anant Asankhya is the manager at the INFINITE hotel. The hotel has an infinite amount of rooms.

# One fine day, a finite number of tourists come to stay at the hotel.
# The tourists consist of:
# → A Captain.
# → An unknown group of families consisting of KK members per group where KK ≠ 11.

# The Captain was given a separate room, and the rest were given one room per group.

# Mr. Anant has an unordered list of randomly arranged room entries. The list consists of the room numbers for all of the tourists. The room numbers will appear KK times per group except for the Captain's room.

# Mr. Anant needs you to help him find the Captain's room number.
# The total number of tourists or the total number of groups of families is not known to you.
# You only know the value of KK and the room number list.

# Input Format

# The first line consists of an integer, KK, the size of each group.
# The second line contains the unordered elements of the room number list.


# Constraints

# 1<K<10001<K<1000
# Output Format

# Output the Captain's room number.

# Sample Input

# 5
# 1 2 3 6 5 4 4 2 5 3 6 1 6 5 3 2 4 1 2 5 1 4 3 6 8 4 3 1 5 6 2
# Sample Output

# 8
# Explanation

# The list of room numbers contains 3131 elements. Since KK is 55, there must be 66 groups of families. In the given list, all of the numbers repeat 55 times except for room number 88.
# Hence, 88 is the Captain's room number.

from collections import Counter
K, a = input(), Counter(map(int, input().split()))
[print(i) for i in a.elements() if a[i]==1]
