#include <iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

void rec_func() {
	int c=0;	
	cin >> c;
	if (c != 0) {
		rec_func();
		cout << c << " ";
	} 
	return;
}

int main() {
	int a=0;
	int b=0;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	
	rec_func();
	return 0;
}
