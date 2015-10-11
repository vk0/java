#include <iostream>
#include "merge.h"

int main()
{
	char array[] = {'9','0','1','3','2','4','5','8','7','6','\0'};
	char buffer[11];

	std::cout << "source array = " << array << std::endl;
	merge_sort(array, 5 , buffer);
	std::cout << "sorted array = " << array << std::endl;

	return 0;
}
