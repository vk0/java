# # -*- coding: utf-8 -*-
# You are given a valid XML document, and you have to print its score. The score is calculated by the sum of the score of each element. For any element, the score is equal to the number of attributes it has.

# Input Format

# The first line contains NN, the number of lines in the XML document.
# The next NN lines follow containing the XML document.

# Output Format

# Output a single line, the integer score of the given XML document.

# Sample Input

# 6
# <feed xml:lang='en'>
#     <title>HackerRank</title>
#     <subtitle lang='en'>Programming challenges</subtitle>
#     <link rel='alternate' type='text/html' href='http://hackerrank.com/'/>
#     <updated>2013-12-25T12:00:00</updated>
# </feed>
# Sample Output

# 5
# Explanation

# The feed and subtitle tag have one attribute each - lang.
# The title and updated tags have no attributes.
# The link tag has three attributes - rel, type and href.

# So, the total score is 1+1+3=51+1+3=5.

# There may be any level of nesting in the XML document. To learn about XML parsing, refer here.

# NOTE: In order to parse and generate an XML element tree, use the following code:

# >> import xml.etree.ElementTree as etree
# >> tree = etree.ElementTree(etree.fromstring(xml))
# Here, XML is the variable containing the string.
# Also, to find the number of keys in a dictionary, use the len function:

# >> dicti = {'0': 'This is zero', '1': 'This is one'}
# >> print (len(dicti))

# 2

import xml.etree.ElementTree as etree

# Combine the rows into a string
xml_string ='\n'.join([input() for _ in range(int(input()))])

# Convert string into XML tree
xml_tree = etree.ElementTree(etree.fromstring(xml_string))

# Add the attributes of the root element to the sum of the attributes of all the children of the root element
print(len(xml_tree.getroot().attrib) + sum([len(element.attrib) for element in xml_tree.findall('.//')]))