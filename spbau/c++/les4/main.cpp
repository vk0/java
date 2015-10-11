#include <iostream>
#include "array.h"

#define SIZE 10

void print(const Array &array)
{
	std::cout << "array:\n\t[";
	for (size_t i = 0; i < array.getsize(); i++)
		std::cout << array.get(i) << " ";
	std::cout << "]" << std::endl;
}

int main()
{
	Array ints(SIZE);

	std::cout << "Adding integers from 0 to " << SIZE-1 << std::endl;
	for (size_t i = 0; i < SIZE; i++)
		ints.set(i, static_cast<int>(i));

	std::cout << "lets see results ";
	print(ints);

	Array copy = ints;
	std::cout << "lets see at copied array ";
	print(copy);

	std::cout << "lets change first element on 5" << std::endl;
	copy.set(0, 5);
	print(copy);

	ints = copy;
	std::cout << "after ints = copy ints looks like ";
	print(ints);

	std::cout << "And now lets touch " << SIZE << " element" << std::endl;
	std::cout << "\t" << ints.get(SIZE);

	return 0;
}
