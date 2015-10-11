#include <iostream>
#include "object.h"

object::object()
{
	std::cout << "object constructor" << std::endl;
}

object::~object()
{
	std::cout << "object destructor" << std::endl;
}

void object::foo()
{
	std::cout << "foooo" << std::endl;
}
