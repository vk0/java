# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(n):
    sortedEnd = sorted(n, key=lambda x: x[1])
    sortedBeg = sorted(n, key=lambda x: x[0])
    thrhold = sortedBeg[0][0] - 1
    #print (sortedBeg)
    #print (sortedEnd)
    listOfPoints = []
    for i in range(len(sortedEnd)-1):
        beg, end = sortedEnd[i]
        if beg > thrhold:
            listOfPoints.append(end)
            thrhold = end

    if listOfPoints[-1] < sortedEnd[-1][0]:
        if sortedEnd:
            listOfPoints.append(sortedEnd[len(sortedEnd) - 1][0])
    result = []
    for p in listOfPoints:
        result.append(p)
    return result

# def optimal_points(segments):
#     points = []
#     #write your code here
#     for s in segments:
#         points.append(s.start)
#         points.append(s.end)
#     return points

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))
    points = optimal_points(segments)
    print(len(points))
    for p in points:
        print(p, end=' ')
