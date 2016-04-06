# Given NN integers, compute their average correct to three decimal places.

# Input Format
# The first line contains an integer, NN.
# NN lines follow, each containing a single integer.

# Output Format
# Display the average of the NN integers, rounded off to three decimal places.

# Input Constraints
# 1≤N≤5001≤N≤500
# −10000≤x≤10000−10000≤x≤10000 (xx refers to elements of the list of integers for which the average is to be computed)

# Sample Input

# 4
# 1
# 2
# 9
# 8
# Sample Output

# 5.000
# Explanation
# The '4' in the first line indicates that there are four integers whose average is to be computed. The average = (1 + 2 + 9 + 8)/4 = 20/4 = 5.000 (correct to three decimal places) Please include the zeroes even if they are redundant (e.g. 0.000 instead of 0).

sum=0
read num
while IFS= read -r line || [[ -n "$line" ]]; do
    sum=$(($sum + $line))
done
printf "%.3f" $(echo "scale=10; $sum/$num" | bc -l)