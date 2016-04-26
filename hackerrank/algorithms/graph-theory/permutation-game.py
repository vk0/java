# # -*- coding: utf-8 -*-
# Alice and Bob play the following game:

# They choose a permutation of the first NN numbers to begin with.
# They play alternately and Alice plays first.
# In a turn, they can remove any one remaining number from the permutation.
# The game ends when the remaining numbers form an increasing sequence. The person who played the last turn (after which the sequence becomes increasing) wins the game.
# Assuming both play optimally, who wins the game?

# Input Format:
# The first line contains the number of test cases TT. TT test cases follow. Each case contains an integer NN on the first line, followed by a permutation of the integers 1..N1..N on the second line.

# Output Format:
# Output TT lines, one for each test case, containing "Alice" if Alice wins the game and "Bob" otherwise.

# Constraints:

# 1<=T<=1001<=T<=100
# 2<=N<=152<=N<=15
# The permutation will not be an increasing sequence initially.

# Sample Input:

# 2
# 3
# 1 3 2
# 5
# 5 3 2 1 4
# Sample Output:

# Alice
# Bob
# Explanation:
# For the first example, Alice can remove the 33 or the 22 to make the sequence increasing and wins the game.

# For the second example, if 44 is removed then the only way to have an increasing sequence is to only have 11 number left, which would take a total of 44 moves, thus allowing Bob to win. On the first move if Alice removes the 44, it will take 33 more moves to create an increasing sequence thus Bob wins. If Alice does not remove the 44, then Bob can remove it on his next turn since Alice can not win in one move.

def count_node(v_list, m, n):
    count = [1 for i in range(m)]

    for child, parent in reversed(v_list):
        count[parent-1] += count[child-1]

    return count

def even_tree(v_list, m, n):
    count = count_node(v_list, m, n)

    cut_count = -1
    for i in count:
        if i % 2 == 0:
            cut_count += 1

    return cut_count

if __name__ == "__main__":
    m, n = [int(i) for i in raw_input().split()]
    v_list = []
    for i in range(n):
        v_list.append((int(i) for i in raw_input().split()))
    print(even_tree(v_list, m, n))