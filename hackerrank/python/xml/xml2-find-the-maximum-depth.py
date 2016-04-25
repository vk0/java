# -*- coding: utf-8 -*-
# You are given a valid XML document, and you have to print the maximum level of nesting in it. Take the depth of the root as 00.

# Input Format

# The first line contains NN, the number of lines in the XML document.
# The next NN lines follow containing the XML document.

# Output Format

# Output a single line, the integer value of the maximum level of nesting in the XML document.

# Sample Input

# 6
# <feed xml:lang='en'>
#     <title>HackerRank</title>
#     <subtitle lang='en'>Programming challenges</subtitle>
#     <link rel='alternate' type='text/html' href='http://hackerrank.com/'/>
#     <updated>2013-12-25T12:00:00</updated>
# </feed>
# Sample Output

# 1
# Explanation

# Here, the root is a feed tag, which has depth of 00.
# The tags title, subtitle, link and updated all have a depth of 11.

# Thus, the maximum depth is 11.


import xml.etree.ElementTree as etree
xml_string ='\n'.join([input() for _ in range(int(input()))])
xml_tree = etree.ElementTree(etree.fromstring(xml_string))

def maximumdepth(node, depth):
    if len(node) == 0:
        return depth
    else:
        maximum = depth
        for child in node:
            maximum = max(maximumdepth(child, depth + 1), maximum)
        return maximum

print (maximumdepth(xml_tree.getroot(), 0))