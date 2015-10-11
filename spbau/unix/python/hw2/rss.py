#!/usr/bin/python

import xml.etree.ElementTree as etree

def printrss(root, indention):
	print indention, root.tag, ":"
	if root.text:
		lines = root.text.split("\n")
		for line in lines:
			print indention + "   ", line
	for child in root:
		printrss(child, indention + "   ")

tree = etree.parse('feed')
root = tree.getroot()
printrss(root,"")
