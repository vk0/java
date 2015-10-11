#!/usr/bin/python

import copy

name = input()
lines = file(name).readlines()

def levinstein(str1, str2):
	if str1 == str2:
		return 0

	firstlen = len(str1)
	secondlen = len(str2)
	cost = [[0 for i in xrange(secondlen+1)] for j in xrange(firstlen+1)]
	for i in xrange(firstlen+1):
		cost[i][0] = i
	for i in xrange(secondlen+1):
		cost[0][i] = i

	for i in xrange(firstlen):
		for j in xrange(secondlen):
			val = 0;
			if str1[i] != str2[j]:
				val = 1;
			cost[i+1][j+1] = min(cost[i][j+1]+1, cost[i+1][j]+1, cost[i][j]+val)

	return cost[-1][-1]

first = lines[0]
firstnum = -1

second = lines[1]
secondnum = -1

words = lines[3:len(lines)]

graph = [[0 for i in xrange(len(words))] for i in xrange(len(words))]
for i in xrange(len(words)):
	if words[i] == first:
		firstnum = i
	if words[i] == second:
		secondnum = i
	for j in xrange(len(words)):
		if (levinstein(words[i],words[j])==1) or (i==j):
			graph[i][j] = 1;

def findnextunused(distance, used):
	mindist = -1;
	nextv = -1;
	for i in xrange(len(used)):
		if not used[i]:
			if (mindist==-1) and not (distance[i] == -1):
				mindist = distance[i]
				nextv = i
			else:
				if not (distance[i] == -1) and (distance[i] < mindist):
					mindist = distance[i]
					nextv = i
	return nextv

def findpath(graph, src, dst):
	length = [-1 for i in xrange(len(graph))]
	length[src] = 0
	used = [False for i in xrange(len(graph))]
	path = [[] for i in xrange(len(graph))]
	path[src].append(src);
	v = findnextunused(length, used)
	while not (v == -1):
		for i in xrange(len(graph)):
			if not used[i] and graph[v][i] == 1:
				if (length[i] > length[v] + 1) or (length[i] == -1):
					if length[i] == -1:
						length[i] = 0
					length[i] = length[v] + 1
					path[i] = copy.deepcopy(path[v])
					path[i].append(i)
		used[v] = True
		v = findnextunused(length, used)
	return path[dst]

if not (firstnum == -1) and not (secondnum == -1):
	path = findpath(graph, firstnum, secondnum)
	if len(path) > 0:
		for i in path:
			print words[i],
	else:
		print "Impossible"
else:
	print "Impossible"
