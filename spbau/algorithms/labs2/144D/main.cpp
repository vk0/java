#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using std::vector;
using std::pair;
using std::deque;

typedef vector<pair<size_t, long> > neighbors_t;
typedef vector<neighbors_t> graph_t;

template <class F, class S, class T>
struct tuple3
{
	tuple3(F const &f, S const &s, T const &t)
	: first(f)
	, second(s)
	, third(t)
	{}
	
	tuple3() {}
	
	F first;
	S second;
	T third;
};

typedef tuple3<size_t, size_t, long> edge_t;

void levit(graph_t const &graph, size_t src, vector<long> &distances)
{
	distances.resize( graph.size() );
	vector<bool> visited( graph.size() );
	std::fill(distances.begin(), distances.end(), -1);
	std::fill(visited.begin(), visited.end(), false);
	distances[src] = 0;

	deque<size_t> queue;
	queue.push_back(src);
	
	while ( !queue.empty() )
	{
		size_t v = queue.front();
		queue.pop_front();
		visited[v] = true;
		for (neighbors_t::const_iterator it = graph[v].begin(); it != graph[v].end(); ++it)
		{
			size_t u = it->first;
			long dist = distances[v] + it->second;
			if (!visited[u])
			{
				visited[u] = true;
				distances[u] = dist;
				queue.push_back(u);
			}
			else if (dist < distances[u])
			{
				queue.push_front(u);
				distances[u] = dist;
			}
		}
	}	
}

int main(int argc, char **argv)
{
	size_t cities, rouds, capital;
	std::cin >> cities >> rouds >> capital;

	vector<edge_t> edges(rouds);
	graph_t graph(cities + 1);
	for (size_t i = 0; i != rouds; ++i)
	{
		size_t c1, c2;
		long len;
		std::cin >> c1 >> c2 >> len;
		graph[c1].push_back(std::make_pair(c2, len));
		graph[c2].push_back(std::make_pair(c1, len));
		edges[i] = edge_t(c1, c2, len);
	}
	
	long distance;
	std::cin >> distance;
	
	vector<long> distances;
	levit(graph, capital, distances);
	
	size_t result = 0;
	
	for (vector<edge_t>::const_iterator it = edges.begin(); it != edges.end(); ++it)
	{
		size_t v = it->first;
		size_t u = it->second;
		long w = it->third;
		long cicle = distances[u] + distances[v] + w;
		
		if (distances[u] < distance && distance - distances[u] < w && cicle > 2 * distance)
			++result;
		if (distances[v] < distance && distance - distances[v] < w && cicle > 2 * distance)
			++result;
		if (distances[u] < distance && distances[v] < distance && cicle == 2 * distance)
			++result;
	}
	
	for (vector<long>::const_iterator it = distances.begin(); it != distances.end(); ++ it)
		if (*it == distance)
			++result;
	
	std::cout << result << std::endl;
	
	return 0;
}