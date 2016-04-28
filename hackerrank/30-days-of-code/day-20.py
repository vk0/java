# -*- coding: utf-8 -*-
# Objective
# Today, we're discussing a simple sorting algorithm called Bubble Sort. Check out the Tutorial tab for learning materials and an instructional video!

# Consider the following version of Bubble Sort:

# for (int i = 0; i < n; i++) {
#     int numberOfSwaps = 0;

#     for (int j = 0; j < n - 1; j++) {
#         if (a[j] > a[j + 1]) {
#             swap(a[j], a[j + 1]);
#             numberOfSwaps++;
#         }
#     }

#     if (numberOfSwaps == 0) {
#         break;
#     }
# }
# Task
# Given an array, aa, of size nn containing distinct elements a[0],a[1],…,a[n−1]a[0],a[1],…,a[n−1], sort array aa in ascending order using the Bubble Sort algorithm above. Once sorted, print the following 33 lines:

# Array is sorted in numSwaps swaps.Array is sorted in numSwaps swaps.
# where numSwapsnumSwaps is the number of swaps that took place.
# First Element: firstElementFirst Element: firstElement
# where firstElementfirstElement is the first element in the sorted array.
# Last Element: lastElementLast Element: lastElement
# where lastElementlastElement is the last element in the sorted array.
# Hint: To complete this challenge, you will need to add a variable that keeps a running tally of all swaps that occur during execution.

# Input Format

# The first line contains an integer, nn, denoting the number of elements in array aa.
# The second line contains nn space-separated integers describing aa, where the ithith integer is a[i]a[i], ∀ i∈[0, n−1]∀ i∈[0, n−1].

# Constraints

# 2≤n≤2×1042≤n≤2×104
# 1≤a[i]≤2×1061≤a[i]≤2×106, ∀ i∈[0, n−1]∀ i∈[0, n−1]
# Output Format

# There should be 33 lines of output:

# Array is sorted in numSwaps swaps.Array is sorted in numSwaps swaps.
# where numSwapsnumSwaps is the number of swaps that took place.
# First Element: firstElementFirst Element: firstElement
# where firstElementfirstElement is the first element in the sorted array.
# Last Element: lastElementLast Element: lastElement
# where lastElementlastElement is the last element in the sorted array.
# Sample Input 0

# 3
# 1 2 3
# Sample Output 0

# Array is sorted in 0 swaps.
# First Element: 1
# Last Element: 3
# Sample Input 1

# 3
# 3 2 1
# Sample Output 1

# Array is sorted in 3 swaps.
# First Element: 1
# Last Element: 3
# Explanation

# Sample Case 1:
# The array is already sorted, so 00 swaps take place and we print the necessary 33 lines of output shown above.

# Sample Case 2:
# The array is not sorted, and its initial values are: {3, 2, 1}{3, 2, 1}. The following 33 swaps take place:

# {3, 2, 1}→{2, 3, 1}{3, 2, 1}→{2, 3, 1}
# {2, 3, 1}→{2, 1, 3}{2, 3, 1}→{2, 1, 3}
# {2, 1, 3}→{1, 2, 3}{2, 1, 3}→{1, 2, 3}
# At this point the array is sorted and we print the necessary 33 lines of output shown above.

import sys

n = int(input())
a = [int(i) for i in input().strip().split(' ')]
numSwaps = 0

for i in range(n):
    currentSwaps = 0

    for j in range(0, n - 1):
        if a[j] > a[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
            currentSwaps += 1
            numSwaps += 1

    if currentSwaps == 0:
        break

print("Array is sorted in " + str(numSwaps) + " swaps.")
print("First Element: " + str(a[0]))
print("Last Element: " + str(a[n - 1]))