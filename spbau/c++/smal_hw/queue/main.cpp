#include <iostream>
#include <algorithm>
#include <vector>

#include "priority_queue.h"

template <typename T>
bool greater(T const &l, T const &r) { return l > r; }

typedef bool (*cmp)(int const &,int const &);

int main(int argc, char **argv)
{
	std::vector<int> v;
	for (int i = 10; i > 0; --i)
		v.push_back(i);
	std::random_shuffle(v.begin(), v.end());

	priority_queue<int, cmp> decending_queue(v, &greater<int>);
	priority_queue<int> ascending_queue(decending_queue);

	while ( !decending_queue.empty() )
	{
		std::cout << decending_queue.top() << " ";
		decending_queue.pop();
	}
	std::cout << std::endl;

	decending_queue = ascending_queue;
	for (priority_queue<int, cmp>::const_iterator it = decending_queue.begin();
			it != decending_queue.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	for (priority_queue<int, cmp>::const_iterator it = ascending_queue.begin();
			it != ascending_queue.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return 0;
}
