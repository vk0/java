#!/usr/bin/python

import sys
import re

matcher = re.compile("<cite>(?:(?:[a-z0-9-]+)[.])+([a-z]{2,4}){1}[^a-z]")
page = sys.stdin.read()
domens = matcher.findall(page)
counter = {}
for domen in domens:
	if domen not in counter:
		counter[domen]=1
	else:
		counter[domen]=counter[domen]+1

print counter

