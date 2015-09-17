#include <iostream>
using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int result = 0;

	cin >> a >> b;

	for (int i = a; i < b; i++) {
		if (i % 400 == 0) {
			result++;
		} else if ((i % 4 == 0) && (i % 100 != 0)) {
			result++;
		}
	}
	
	cout << result << endl;

	return 0;
}
