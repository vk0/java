#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::vector;
using std::swap;
using std::copy;
using std::sort;
using std::istream_iterator;
using std::back_inserter;
using std::cin;
using std::cout;

int main(int argc, char ** argv)
{
	vector<int> v;
	int dummy, value;

	cin >> dummy;
	istream_iterator<int> in(cin);
	istream_iterator<int> end;
	copy(in, end, back_inserter(v));

	vector<int>::iterator max = v.begin();
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		if (*it > *max) max = it;

	if (*max == 1) *max = 2;
	else *max = 1;

	sort(v.begin(), v.end());

	for (vector<int>::const_iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << " ";

	return 0;
}
