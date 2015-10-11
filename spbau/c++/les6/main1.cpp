#include <iostream>

class A {
public:
	A() {
		int **tmp = (int**)this;
//		std::cout << "vtableA = " << this << std::endl;
//		for (int i = 0; i < 5; i++)
	
//		std::cout << i << ": " << (void *)(*(tmp+i)) << std::endl;

		for (int i = 0; i < 3; i++)
			std::cout << i << ": " << (void *) (*(*tmp + i)) << std::endl;
	}

	virtual void foo() {};

	virtual ~A() {
		std::cout << "vtableA = " << this << std::endl;
	}
};

class B : public A {
public:
	B() : A() {
		int **tmp = (int **)this;
//		std::cout << "vtableB = " << this << std::endl;
		for (int i = 0; i < 5; i++)
			std::cout << i << ": " << (void *)(*(*tmp+i)) << std::endl;
	}

	virtual ~B() {
		std::cout << "vtableB = " << this << std::endl;
	}
};

int main() {
	A *a = new B();
	delete a;

	A *b = new A();
	delete b;

	return 0;
}
