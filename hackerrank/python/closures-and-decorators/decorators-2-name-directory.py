# # -*- coding: utf-8 -*-
# Let's use decorators to build a name directory! You are given some information about NN people. Each person has a first name, last name, age and sex. Print their names in a specific format sorted by their age in ascending order i.e. the youngest person's name should be printed first. For two people of the same age, print them in the order of their input.

# For Henry Davids, the output should be:

# Mr. Henry Davids
# For Mary George, the output should be:

# Ms. Mary George
# Input Format

# The first line contains the integer NN, the number of people.
# NN lines follow each containing the space separated values of the first name, last name, age and sex, respectively.

# Constraints

# 1≤N≤101≤N≤10
# Output Format

# Output NN names on separate lines in the format described above in ascending order of age.

# Sample Input

# 3
# Mike Thomson 20 M
# Robert Bustle 32 M
# Andria Bustle 30 F
# Sample Output

# Mr. Mike Thomson
# Ms. Andria Bustle
# Mr. Robert Bustle
# Concept

# For sorting a nested list based on some parameter, you can use the itemgetter library. You can read more about it here.

peoples = [input() for _ in range(int(input()))]

def peopleformat(func):
    def peopletoformat(peoples):
        for i in range(len(peoples)):
            temp = peoples[i].strip().split()
            if temp[-1] == 'M':
                flag = 'Mr. '
            else:
                flag = 'Ms. '
            peoples[i] = [flag + ' '.join(temp[:-2]), int(temp[-2])]
        return func(peoples)
    return peopletoformat

@peopleformat
def peoplesort(peoples):
    for x, y in sorted(peoples, key=lambda x: x[1]):
        print(x)

peoplesort(peoples)