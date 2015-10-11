#include <iostream>

#include "slist.h"

int main() {
	slist<int> list;
	
	for (int i = 0; i != 10; i++)
		list.push_front(i);

	for (slist<int>::iterator it = list.begin(); it != list.end(); ++it)
		std::cout << *it;
		
	return 0;
}