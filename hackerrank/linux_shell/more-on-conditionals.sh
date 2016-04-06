# if statements in Bash are often used in four important ways:

# 1. if...then...fi statements
# 2. if...then...fi...else statements
# 3. if..elif..else..fi
# 4. if..then..else..if..then..fi..fi.. (Nested Conditionals)
# The Recommended Resources section may give you a clearer idea of conditionals in Bash.

# Your task:
# Given three integers (XX, YY, and ZZ) representing the three sides of a triangle, identify whether the triangle is Scalene, Isosceles, or Equilateral.

# Input Format
# Three integers, each on a new line.

# Input Constraints
# 1≤X,Y,Z≤10001≤X,Y,Z≤1000
# Sum of any two sides will be greater than the third.

# Output Format
# One word: either "SCALENE" or "EQUILATERAL" or "ISOSCELES" (quotation marks excluded).

# Sample Input 1

# 2
# 3
# 4
# Sample Output 1

# SCALENE
# Sample Input 2

# 6
# 6
# 6
# Sample Output 2

# EQUILATERAL
# Recommended Resources

# A quick but useful tutorial for Bash newcomers is here.
# Handling input is documented and explained quite well on this page.
# Different ways in which 'if' statements may be used in Bash are demonstrated here.

read x
read y
read z
[[ $x -eq $y ]] && ([[ $y -eq $z ]] && echo EQUILATERAL || echo ISOSCELES) || ([[ $y -eq $z ]] && echo ISOSCELES || echo SCALENE)