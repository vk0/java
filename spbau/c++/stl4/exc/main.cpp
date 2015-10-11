#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
#include <cassert>

template <class Type>
struct nth
{
	const size_t n;
	size_t counter;
	
	nth(size_t step)
	: n(step)
	, counter(0)
	{}
	
	bool operator()(Type const &it)
	{
		return ((++counter % n) == 0);
	}
};

template <class InputIterator, class OutputIterator>
OutputIterator remove_copy_every(InputIterator p, InputIterator q, OutputIterator o, size_t n)
{
	return std::remove_copy_if(p, q, o, nth<typename InputIterator::value_type>(n));
}

template <class Type>
void swap3(Type &a, Type &b, Type &c)
{
	std::swap(b, c);
	std::swap(a, b);
}

template <class T, class Stack>
class StackInputIterator : public std::iterator<std::input_iterator_tag, T>
{
public:
	explicit StackInputIterator(Stack &st)
	: myStack(&st)
	{}
	
	T operator*() const
	{
		assert(!myStack->empty());
		T t(myStack->top());
		myStack->pop();
		return t;
	}
	
	StackInputIterator<T, Stack>& operator++()
	{
		assert(!myStack->empty());
		myStack->pop();
		return *this;
	}
	
	StackInputIterator<T, Stack> operator++(int)
	{
		assert(!myStack->empty());
		StackInputIterator<T, Stack> it(*this);
		myStack->pop();
		return it;
	}
	
private:
	Stack *myStack;
};

template <class T, class V>
StackInputIterator<T, std::stack<T, V> > popper(std::stack<T, V> &st)
{
	return StackInputIterator<T, std::stack<T, V> >(st);
}

int main()
{
	std::vector<int> v1;
	std::vector<int> v2;
	
	int a = 1;
	int b = 2;
	int c = 3;
	
	swap3(a, b, c);
	std::cout << a << " " << b << " " << c << std::endl;
	
	for (int i = 0; i < 10; ++i)
		v1.push_back(i);
	
	remove_copy_every(v1.begin(), v1.end(), std::back_inserter(v2), 3);
	
	for (std::vector<int>::const_iterator it = v2.begin(); it != v2.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::stack<int, std::vector<int> > st(v1);
	StackInputIterator<int, std::stack<int, std::vector<int> > > it = popper(st);	
	for (;;)
	{
		std::cout << *it << std::endl;		
	}
	
	return 0;
}