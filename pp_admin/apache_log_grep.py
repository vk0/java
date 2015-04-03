import re
import shlex

def grep(lines,pattern='Mozilla'):
    pat = re.compile(pattern)
    for line in lines:
        if pat.search(line):
            yield line

def increment(lines):
    num = 0
    for line in lines:
        num += 1
    return num

wwwlog = open('apache.log')
column = (shlex.split(line)[9] for line in wwwlog.readlines())
match = grep(column)
count = increment(match)
print('Total Number of Mozilla Hits: %s' % count)