# # -*- coding: utf-8 -*-
# CSS colors are defined using a hexadecimal (HEX) notation for the combination of Red, Green, and Blue color values (RGB).

# Specifications of HEX Color Code

# ■ It must start with a '#' symbol.
# ■ It can have 33 or 66 digits.
# ■ Each digit is in the range of 00 to FF. (1,2,3,4,5,6,7,8,9,0,A,B,C,D,E1,2,3,4,5,6,7,8,9,0,A,B,C,D,E and FF).
# ■ A−FA−F letters can be lower case. (a,b,c,d,ea,b,c,d,e and ff are also valid digits).

# Examples

# Valid Hex Color Codes
# #FFF
# #025
# #F0A1FB

# Invalid Hex Color Codes
# #fffabg
# #abcf
# #12365erff
# You are given NN lines of CSS code. Your task is to print all valid Hex Color Codes, in order of their occurrence from top to bottom.

# CSS Code Pattern

# Selector
# {
#     Property: Value;
# }
# Input Format

# The first line contains NN, the number of code lines.
# The next NN lines contains CSS Codes.

# Constraints

# 0<N<500<N<50

# Output Format

# Output the color codes with '#' symbols on separate lines.

# Sample Input

# 11
# #BED
# {
#     color: #FfFdF8; background-color:#aef;
#     font-size: 123px;
#     background: -webkit-linear-gradient(top, #f9f9f9, #fff);
# }
# #Cab
# {
#     background-color: #ABC;
#     border: 2px dashed #fff;
# }
# Sample Output

# #FfFdF8
# #aef
# #f9f9f9
# #fff
# #ABC
# #fff
# Explanation

# #BED and #Cab satisfy the Hex Color Code criteria, but they are used as selectors and not as color codes in the given CSS.

# Hence, the valid color codes are:

# #FfFdF8
# #aef
# #f9f9f9
# #fff
# #ABC
# #fff

# Note: There are no comments ( // or /* */) in CSS Code.

import re

for _ in range(int(input())):
    m = re.findall(r'(?<!^)#[0-9a-f]{3,6}', input().strip(), flags = re.I)
    if m:
        print('\n'.join(m))