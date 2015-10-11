#include <vector>
#include <iostream>

template <class C, class A, class R>
struct Functor : std::binary_function<C, A, R>
{
	typedef R (C::* method_t) (A);
	Functor(method_t method)
		: myMethod(method)
	{}
	
	R operator()(C &c, A a) const { return (c.*myMethod)(a); }
	method_t myMethod;
};

template <class C, class A, class R>
struct ConstFunctor : std::binary_function<C, A, R>
{
	typedef R (C::* method_t) (A) const;
	ConstFunctor(method_t method)
		: myMethod(method)
	{}
	
	R operator()(C const &c, A a) const { return (c.*myMethod)(a); }
	method_t myMethod;
};

template <class C, class A, class R>
Functor<C, A, R> mem_fun1_ref(R (C::*method)(A))
{
	return Functor<C, A, R>(method);
}

template <class C, class A, class R>
ConstFunctor<C, A, R> mem_fun1_ref(R (C::* method) (A) const)
{
	return ConstFunctor<C, A, R>(method);
}

class test
{
public:
	size_t method(size_t arg) { return arg; }
};

int main(int argc, char** argv)
{
	std::vector<int> v(4);
	(mem_fun1_ref(&std::vector<int>::push_back))(v, 5);
	std::cout << v.size() << std::endl;
	
	return 0;
}