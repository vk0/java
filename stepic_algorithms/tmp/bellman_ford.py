from decimal import Decimal as d

class Edge(object):
    def __init__(self, source, target, weight):
        self.s = source
        self.t = target
        self.w = weight
    
class Graph(object):
    def __init__(self, n):
        self.has_cycle = False
        self.v = n
        self.e = set()

    def add_edge(self, e):
        self.e.add(e)

    def bf(self, s):
        if self.has_cycle: return

        self.dist = [d('Infinity') for i in range(0, self.v + 1)]
        self.dist[s] = 0
        
        for i in range(0, self.v):
            for edge in self.e:
                if self.dist[edge.s] > self.dist[edge.t] + edge.w:
                    self.dist[edge.s] = self.dist[edge.t] + edge.w

        for i in range(1):
            for edge in self.e:
                if self.dist[edge.s] > self.dist[edge.t] + edge.w:
                    self.has_cycle = True
                    return


if __name__ == '__main__':
    n, m = map(int, input().split())
    g = Graph(n)

    for i in range(0, m):
        s, t, w = map(int, input().split())
        g.add_edge(Edge(s, t, w))

    for i in range(1, g.v):
        if g.has_cycle: break
        g.bf(i)

    print(g.has_cycle)
