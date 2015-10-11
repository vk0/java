#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include <functional>
#include "rbtree.h"

template <typename Data, typename Comp = std::less<Data> >
class priority_queue : public rbtree<Data, Comp>
{
public:
	typedef rbtree_iterator<Data> const_iterator;

	priority_queue(Comp const &c)
	: rbtree<Data, Comp>(c)
	{}

	priority_queue()
	{}

	template <typename FwdIterator>
	priority_queue(FwdIterator const &b, FwdIterator const &e)
	: rbtree<Data, Comp>(b, e)
	{}

	template <typename FwdIterator>
	priority_queue(FwdIterator const &b, FwdIterator const &e, Comp const &cmp)
	: rbtree<Data, Comp>(b, e, cmp)
	{}

	template <typename Container>
	priority_queue(Container const &c)
	: rbtree<Data, Comp>(c)
	{}

	template <typename Container>
	priority_queue(Container const &c, Comp const &cmp)
	: rbtree<Data, Comp>(c, cmp)
	{}

	template <typename Container>
	priority_queue<Data, Comp> & operator=(Container const & c)
	{
		rbtree<Data, Comp>::operator=(c);
		return *this;
	}

	Data const & top() const { return this->begin().rbtree_node()->data; }
	void push(Data const &val) { this->insert(val); }
	void pop() { this->erase(this->begin()); }
};

#endif /* __PRIORITY_QUEUE_H__ */
