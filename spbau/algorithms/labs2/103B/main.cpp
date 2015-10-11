#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

using std::vector;
using std::deque;

typedef vector<vector<size_t> > graph_t;

size_t bfs(graph_t const &graph)
{
	size_t count = 1;
	std::vector<bool> visited( graph.size() );
	std::fill(visited.begin(), visited.end(), false);
	std::deque<size_t> queue;

	visited[1] = true;
	queue.push_back(1);

	while ( !queue.empty() )
	{
		size_t v = queue.front();
		queue.pop_front();
		for (vector<size_t>::const_iterator it = graph[v].begin(); it != graph[v].end(); ++it)
			if (!visited[*it])
			{
				visited[*it] = true;
				queue.push_back(*it);
				++count;
			}
	}

	return count;
}

int main(int argc, char **argv)
{
	size_t edges, vertexes;

	std::cin >> vertexes >> edges;

	if (vertexes == edges)
	{
		size_t v, u;
		graph_t graph(vertexes + 1);
		while (std::cin >> v >> u)
		{
			graph[v].push_back(u);
			graph[u].push_back(v);
		}
		if (bfs(graph) != vertexes)
			std::cout << "NO" << std::endl;
		else
			std::cout << "FHTAGN!" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}

	return 0;
}
