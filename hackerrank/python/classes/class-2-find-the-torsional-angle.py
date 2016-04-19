# -*- coding: utf-8 -*-
# You are given four points A,B,CA,B,C and DD in a 3-dimensional Cartesian coordinate system. You are required to print the angle between the plane made by the points A,B,CA,B,C and B,C,DB,C,D in degrees(not radians). Let the angle be PHIPHI.

# Cos(PHI)=(X.Y)/|X||Y|Cos(PHI)=(X.Y)/|X||Y| where X=ABX=AB x BCBC and Y=BCY=BC x CDCD.

# Here, X.YX.Y means the dot product of XX and YY, and ABAB x BCBC means the cross product of vectors ABAB and BCBC. Also, AB=B−AAB=B−A.

# Input Format

# One line of input containing the space separated floating number values of the X,YX,Y and ZZ coordinates of a point.

# Output Format

# Output the angle correct up to two decimal places.

# Sample Input

# 0 4 5
# 1 7 6
# 0 5 9
# 1 7 2
# Sample Output

# 8.19

import math
class Point(object):

    """Represent a point on a 3d cartesian coordinate system."""

    def __init__(self, x, y, z):
        self.x = float(x)
        self.y = float(y)
        self.z = float(z)

    def cross_product(self, other):
        return Point(
            self.y * other.z - self.z * other.y,
            self.z * other.x - self.x * other.z,
            self.x * other.y - self.y * other.x)

    def dot_product(self, other):
        return (self.x * other.x) + (self.y * other.y) + (self.z * other.z)

    def __abs__(self):
        return math.sqrt(self.x ** 2 + self.y ** 2 + self.z ** 2)

    def __str__(self):
        return '%f, %f, %f' % (self.x, self.y, self.z)

    def __sub__(self, other):
        return Point(
            self.x - other.x,
            self.y - other.y,
            self.z - other.z)

a = Point(*map(float, input().split()))
b = Point(*map(float, input().split()))
c = Point(*map(float, input().split()))
d = Point(*map(float, input().split()))

x = (b - a).cross_product(c - b)
y = (c - b).cross_product(d - c)

cos = x.dot_product(y) / (abs(x) * abs(y))
print('%.2f' % math.degrees(math.acos(cos)))