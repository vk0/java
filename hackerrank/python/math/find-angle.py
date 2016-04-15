# -*- coding: utf-8 -*-
# ABCABC is a right triangle, 90°90° at BB.
# Therefore, ∡ABC=90°∡ABC=90°.

# Point MM is the midpoint of hypotenuse ACAC.

# You are given the lengths ABAB and BCBC.
# Your task is to find ∡MBC∡MBC (angle θ°θ°, as shown in the figure) in degrees.

# Input Format

# The first line contains the length of side ABAB.
# The second line contains the length of side BCBC.

# Constraints

# 0<AB≤1000<AB≤100
# 0<BC≤1000<BC≤100
# Lengths ABAB and BCBC are natural numbers.

# Output Format

# Output ∡MBC∡MBC in degrees.

# Note: Round the angle to the nearest integer.

# Examples:
# If angle is 56.5000001°, then output 57°.
# If angle is 56.5000000°, then output 57°.
# If angle is 56.4999999°, then output 56°.

# 0°<θ°<90°0°<θ°<90°
# Sample Input

# 10
# 10
# Sample Output

# 45°
# NOTE: Python 3 is disabled for this challenge.

import cmath
import math

AB = int(input())
BC = int(input())

A = complex(0, AB)
B = complex(0, 0)
C = complex(BC, 0)

MBC = int(round(math.degrees(cmath.phase(B + C + A))))
print(str(MBC) + "°")