#include <iostream>
#include <string>

class String : public std::string
{
public:
	template <typename Type>
	String & operator=(Type const &str)
	{
		reserve(str.size());
		typename std::string::iterator it(begin());
		str.fill(*this, it);

		return *this;
	}

	String()
	: std::string()
	{
		std::cout << "String created" << std::endl;
	}

	template <typename Type>
	String(Type const &d)
	: std::string(d)
	{
		std::cout << "String created" << std::endl;
	}

	template <typename Holder, typename It>
	void fill(Holder & hld, It & place) const
	{
		hld.insert(hld.end(), begin(), end());
	}
};

template <typename LeftType, typename RightType>
struct Wrapper
{
	Wrapper(LeftType const &str)
	: left(&str)
	, right(0)
	{
		std::cout << "wrapper created" << std::endl;
	}
	
	Wrapper(LeftType const &l, RightType const &r)
	: left(&l)
	, right(&r)
	{
		std::cout << "wrapper created" << std::endl;
	}

	size_t size() const
	{
		size_t length = left->size();
		if (right) length += right->size();
		return length;
	}

	template <typename Holder, typename It>
	void fill(Holder & hld, It & place) const
	{
		if (left) left->fill(hld, place);
		if (right) right->fill(hld, place);
	}
	
	LeftType const * left;
	RightType const * right;
};

template <typename LeftType, typename RightType>
Wrapper<LeftType, RightType> operator+(LeftType const &l, RightType const &r)
{
	return Wrapper<LeftType, RightType>(l, r);
}

int main(int argc, char **argv)
{
	String mystr1("str1");
	String mystr2("str2");
	String mystr3("str3");
	String mystr4("str4");

	String res;
	res = mystr1 + mystr2 + mystr3 + mystr4;

	std::cout << res << std::endl;

	return 0;
}
