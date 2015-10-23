#include <iostream>
#include <iomanip>
using namespace std;
int main(void)
{
   double x=1.234567e-5;
   double y=1.234567e-4;
   double z=5.467e+6;
   double w=5.467e+5;
   cout<<scientific;
   cout<<setprecision(1);
   cout<<"x="<<setw(3)<<x<<endl;
   cout<<"y="<<setw(3)<<y<<endl;
   cout<<"z="<<setw(3)<<z<<endl;
   cout<<"w="<<setw(3)<<w<<endl;
   int hh=9, mm=5;
   cout<<setfill('0')<<setw(15)<<left<<
	   "Time: "<<right<<setw(2)<<hh<<":"<<setw(2)<<mm<<endl;
   return 0;
}
