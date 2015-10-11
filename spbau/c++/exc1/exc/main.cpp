#include <map>
#include <iostream>
#include <boost/shared_ptr.hpp>

template <class Key, class Value>
class mapper
{
public:
	template <class K, class V>
	mapper& operator()(K const &key, V const &val)
	{
		Key k(key);
		Value v(val);
		myMap.insert(std::make_pair(k, v));

		return *this;
	}

	operator std::map<Key, Value>() const
	{
		return myMap;
	}

private:
	std::map<Key, Value> myMap;
};


template <class Key, class Value>
mapper<Key, Value> assign(Key const &key, Value const &value)
{
	return (mapper<Key, Value>()).operator()(key, value);
}

template <class T, class Value>
mapper<boost::shared_ptr<T>, Value> assign(T * key, Value const &value)
{
	return (mapper<boost::shared_ptr<T>, Value>()).operator()(key, value);
}

template <class Key, class T>
mapper<Key, boost::shared_ptr<T> > assign(Key const &key, T * value)
{
	return (mapper<Key, boost::shared_ptr<T> >()).operator()(key, value);
}

template <class T, class U>
mapper<boost::shared_ptr<T>, boost::shared_ptr<U> > assign(T * key, U * value)
{
	return (mapper<boost::shared_ptr<T>, boost::shared_ptr<U> >()).operator()(key, value);
}

int main(int argc, char **argv)
{
	std::map<boost::shared_ptr<int>, boost::shared_ptr<double> > m(assign(new int(1), new double(2.0))(new int(2), new double(3.5)));

	for (std::map<boost::shared_ptr<int>, boost::shared_ptr<double> >::const_iterator it = m.begin(); it != m.end(); ++it)
		std::cout << "(" << *(it->first) << ", " << *(it->second) << ")" << std::endl;

	return 0;
}
