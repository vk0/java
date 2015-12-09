// Ввести строку символов со стандартного входного потока, построив при этом стек состоящий из символов строки, и распечатать строку в обратном порядке.

// Sample Input:

// abcdefgh

// Sample Output:

// hgfedcba

#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string s;
  std::getline(std::cin, s);
  std::reverse(s.begin(), s.end()); // modifies s
  std::cout << s << std::endl;
  return 0;
}