# Given two integers, XX and YY, find their sum, difference, product, and quotient.

# Input Format
# Two lines containing one integer each (XX and YY, respectively).

# Input Constraints
# −100≤X,Y≤100−100≤X,Y≤100
# Y≠0Y≠0
# Output Format
# Four lines containing the sum (X+YX+Y), difference (X−YX−Y), product (X×YX×Y), and quotient (X÷YX÷Y), respectively.
# (While computing the quotient, print only the integer part.)

# Sample Input

# 5
# 2
# Sample Output

# 7
# 3
# 10
# 2
# Reference Resources
# A relevant and interesting discussion on Stack-Exchange for those getting started with handling numbers and arithmetic operations in Bash.

read x
read y
echo "$(($x+$y))"
echo "$(($x-$y))"
echo "$(($x*$y))"
echo "$(($x/$y))"