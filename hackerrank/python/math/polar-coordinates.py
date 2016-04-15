# # -*- coding: utf-8 -*-
# Polar coordinates are an alternative way of representing Cartesian coordinates or Complex Numbers.

# A complex number zz Capture.PNG
# z=x+yj
# z=x+yj
# is completely determined by its real part xx and imaginary part yy.
# Here, jj is the imaginary unit.

# A polar coordinate (r,φr,φ) Capture.PNG

# is completely determined by modulus rr and phase angle φφ.

# If we convert complex number zz to its polar coordinate, we find:
# rr: Distance from zz to origin, i.e., x2+y2−−−−−−√x2+y2
# φφ: Counter clockwise angle measured from the positive xx-axis to the line segment that joins zz to the origin.

# Python's cmath module provides access to the mathematical functions for complex numbers.

# cmath.phasecmath.phase
# This tool returns the phase of complex number zz (also known as the argument of zz).

# >>> phase(complex(-1.0, 0.0))
# 3.1415926535897931
# absabs
# This tool returns the modulus (absolute value) of complex number zz.

# >>> abs(complex(-1.0, 0.0))
# 1.0
# Task
# You are given a complex zz. Your task is to convert it to polar coordinates.

# Input Format

# A single line containing the complex number zz.

# Output Format

# Output two lines:
# The first line should contain the value of rr.
# The second line should contain the value of φφ.

# Sample Input

#   1+2j
# Sample Output

#  2.23606797749979
#  1.1071487177940904
# Note: The output should be correct up to 3 decimal places.

import cmath
import math

eq = input()
pa = cmath.phase(complex(eq))
r = abs(complex(eq))

print("{0}\n{1}".format(r,pa))