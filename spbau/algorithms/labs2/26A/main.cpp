#include <vector>
#include <iostream>

int main(int argc, char** argv)
{
	size_t max;
	size_t counter = 0;

	std::cin >> max;
	std::vector<size_t> numbers;

	for (size_t i = 0; i <= max; ++i)
		numbers.push_back(0);

	for (size_t i = 2; i <= max; ++i)
	{
		if (numbers[i] == 2)
			++counter;
		else if (numbers[i] == 0)
			for (size_t j = i + i; j <= max; j += i)
				++numbers[j];
	}

	std::cout << counter << std::endl;

	return 0;
}
