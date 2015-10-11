#include <iostream>
#include <string>

using std::string;

size_t difference(string const & str1, size_t pos1
		, string const & str2, size_t pos2, size_t len)
{
	size_t count = 0;
	for (size_t i = 0; i < len; ++i) if (str1[pos1 + i] != str2[pos2 + i]) ++count;
	return count;
}

size_t find_min_difference(string const & str, string const & pattern)
{
	size_t diff = pattern.size();
	for (size_t i = 0; i < str.size() - pattern.size() + 1; ++i)
	{
		size_t temp = difference(str, i, pattern, 0, pattern.size());
		if (temp < diff) diff = temp;
	}
	return diff;
}

int main(int argc, char **argv)
{
	string str;
	string pattern;

	getline(std::cin, str);
	getline(std::cin, pattern);

	str.insert(0, pattern.size(), '#');
	str.append(pattern.size(), '#');

	std::cout << find_min_difference(str, pattern) << std::endl;

	return 0;
}
