# Implementation of Depth-First Search
# This algorithm we will be discussing is Depth-First search which as the name hints at, explores possible vertices (from a supplied root) down each branch before backtracking. This property allows the algorithm to be implemented succinctly in both iterative and recursive forms. Below is a listing of the actions performed upon each visit to a node.
# Mark the current vertex as being visited.
# Explore each adjacent vertex that is not included in the visited set.
# We will assume a simplified version of a graph in the following form:

graph = {'A': set(['B', 'C']),
         'B': set(['A', 'D', 'E']),
         'C': set(['A', 'F']),
         'D': set(['B']),
         'E': set(['B', 'F']),
         'F': set(['C', 'E'])}


# Connected Component
# The implementation below uses the stack data-structure to build-up and return a set of vertices that are accessible within the subjects connected component. Using Python’s overloading of the subtraction operator to remove items from a set, we are able to add only the unvisited adjacent vertices.

def dfs(graph, start):
    visited, stack = set(), [start]
    while stack:
        vertex = stack.pop()
        if vertex not in visited:
            visited.add(vertex)
            stack.extend(graph[vertex] - visited)
    return visited

dfs(graph, 'A') # {'A', 'B', 'C', 'D', 'E', 'F'}

# The second implementation provides the same functionality as the first, however, this time we are using the more succinct recursive form. Due to a common Python gotcha with default parameter values being created only once, we are required to create a new visited set on each user invocation. Another Python language detail is that function variables are passed by reference, resulting in the visited mutable set not having to reassigned upon each recursive call.

def dfs(graph, start, visited=None):
    if visited is None:
        visited = set()
    visited.add(start)
    for nxt in graph[start] - visited:
        dfs(graph, nxt, visited)
    return visited

dfs(graph, 'A') # {'A', 'B', 'C', 'D', 'E', 'F'}

# Paths
# We are able to tweak both of the previous implementations to return all possible paths between a start and goal vertex. The implementation below uses the stack data-structure again to iteratively solve the problem, yielding each possible path when we locate the goal. Using a generator allows the user to only compute the desired amount of alternative paths.

def dfs_paths(graph, start, goal):
    stack = [(start, [start])]
    while stack:
        (vertex, path) = stack.pop()
        for nxt in graph[vertex] - set(path):
            if nxt == goal:
                yield path + [nxt]
            else:
                stack.append((nxt, path + [nxt]))

list(dfs_paths(graph, 'A', 'F')) # [['A', 'B', 'E', 'F'], ['A', 'C', 'F']]