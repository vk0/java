
#include <iostream>
using namespace std;
/*
int main(void)
{
	int a, b;
	cin>>a;
	if (cin.fail()) {
		cin.clear();
	}
	cin>>b;
	cout<<a<<" "<<b<<endl;
	return 0;
}
*/
int main(void)
{
	int a;
	bool success = false;
	do
	{
		cin>>a;
		if (cin.fail()) {
			cin.clear();
			char ch;
			cin>>noskipws>>ch;
		} else {
			success = true;
		}
	} while (!success);
	cout<<a<<endl;
	return 0;
}


/*
#include <iostream>
using namespace std;

int main()
{
   int x;
   cout << "enter choice:";
   cin >> x;
   while (x < 1 || x > 4)
   {
      cout << "Invalid choice, try again:";
      cin >> x;
      // not a numeric character, probably
      // clear the failure and pull off the non-numeric character
      if (cin.fail())
      {
         cin.clear();
         char c;
		 do
		 {
			cin >> c;
		 } while (!isdigit(c) && !cin.fail());
		 cin.clear();
		 cin.putback(c);
      }
   }
}
*/