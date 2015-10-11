#include <string>
#include <iostream>
#include <vector>

#include "alpha.h"

int main()
{
	std::string s("alpha whitespaces, nums and signes1234809");
	for (alpha_iterator<std::string::iterator> it(s.begin(), s.end()); it != s.end(); ++it)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	
	std::vector<int> v1(4);
	std::vector<int> v2(16);
	
	std::cout << (v1.end() == v2.end()) << std::endl << (v1.end() == v1.end()) << std::endl;
	
	return 0;
}