#include <iostream>

int main()
{
  int i = 42;
  double d = 3.14;
  //bool b = true; //will print 1
  bool b = false; //will print 0

  std::cout << "Enter an integer and a double:\n";
  std::cin >> i >> d;
  std::cout << "Your input is " << i << ", " << b << ", " << d << "\n";

  return 0;
}