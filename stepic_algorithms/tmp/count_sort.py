import sys
from collections import Counter

def count_sort(array):
	c = Counter(array)
	out = []	
	for el, count in c.items():
		print(count)
		for i in range(1, count+1):
			out.append(el)
			
	return out
		
if __name__ == "__main__":
	input = sys.stdin.read()
	input = input.split("\n")
	n = int(input.pop(0))
	m = map(int, input.pop(0).split())
	m = count_sort(m)
	print(m)
	
