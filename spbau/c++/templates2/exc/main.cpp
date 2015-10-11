#include "stack3.h"

#include <iostream>
#include <vector>
#include <list>
#include <memory>

int main() {
	Stack<int*> pivec;
	Stack<int, std::list> ivec;
	
	ivec.push(10);
	Stack<float> fvec(ivec);
	
	std::cout << fvec.pop() << std::endl;
	
	return 0;
}