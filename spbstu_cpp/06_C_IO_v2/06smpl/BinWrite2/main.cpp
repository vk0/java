#include <iostream>
#include <fstream>
using namespace std;
int main(void)
{
	int arr[20];
	for (int i=0; i<20; i++)
		arr[i]=i;
	ofstream out("out.txt", ios::binary);
	if (!out.is_open())
	{
		cout<<"Error opening file out.txt"<<endl;
		return -1;
	}
	out.write((char*)arr, sizeof(arr));
	return 0;
}
