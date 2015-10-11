#ifndef _ALPHA_H_
#define _ALPHA_H_

#include <iterator>
#include <cctype>
#include <cstddef>

template <class It>
class alpha_iterator : public std::iterator<std::forward_iterator_tag, typename std::iterator_traits<It>::value_type> {
	public:
		alpha_iterator(It p, It q)
		: m_pos(p),
		m_end(q)
		{
			if (!isalpha(*m_pos))
			{
				++m_pos;
			}
		}
		
		alpha_iterator(It end)
		: m_pos(end),
		m_end(end)
		{}
		
		alpha_iterator()
		{}
		
		typename std::iterator_traits<It>::reference operator*()
		{
			return *m_pos;
		}
		
		typename std::iterator_traits<It>::pointer operator->()
		{
			return m_pos.operator->();
		}
		
		alpha_iterator<It>& operator++()
		{
			do
			{
				++m_pos;
			}
			while ((m_pos != m_end) && !isalpha(*m_pos));
			return *this;
		}
		
		alpha_iterator<It>& operator++(int)
		{
			alpha_iterator<It> tmp(*this);
			operator++();
			return tmp;
		}
		
		bool operator==(alpha_iterator<It> const &ai)
		{
			return (m_pos == ai.m_pos) && (m_end == ai.m_end);
		}
		
		bool operator!=(alpha_iterator<It> const &ai)
		{
			return m_pos != ai.m_end;
		}
	private:
		It m_end;
		It m_pos;
};

template <class It>
typename std::iterator_traits<It>::difference_type distance_impl(It b, It e, std::forward_iterator_tag)
{
	std::ptrdiff_t distance = 0;
	while (b != e)
	{
		++b;
		++distance;
	}
	
	return distance;
}

template <class It>
typename std::iterator_traits<It>::differnce_type distance_impl(It b, It e, std::random_access_iterator_tag)
{
	return e - b;
}

template <class It>
typename std::iterator_traits<It>::difference_type distance(It b, It e)
{
	return distance_impl(b, e, std::iterator_traits<It>::iterator_category());
}

#endif //_ALPHA_H_