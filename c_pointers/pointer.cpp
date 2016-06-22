// g++ -Wall pointer.cpp -o pointer

#include <iostream>

int main ()
{
    int variable = 123;
    int *pointer;

    std::cout << "Variable: " << variable << "\n";
    pointer = &variable;
    std::cout << "Pointer: " << *pointer << "\n";
    std::cout << "Variable address in memory: " << pointer << "\n";
    // int newvariable = *pointer;

    return 0;
}