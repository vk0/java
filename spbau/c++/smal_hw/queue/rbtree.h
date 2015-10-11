#ifndef __RB_TREE_H__
#define __RB_TREE_H__

#include <functional>
#include <iterator>
#include <stdexcept>

template <typename Data>
struct rbnode
{
	rbnode<Data> * parent;
	rbnode<Data> * left;
	rbnode<Data> * right;

	bool red;

	Data const data;

	rbnode(Data const & data)
	: parent(0)
	, left(0)
	, right(0)
	, red(true)
	, data(data)
		{}

	rbnode<Data> * findleft()
	{
		rbnode<Data> * p = 0;
		rbnode<Data> * c = this;
		while (c != 0)
		{
			p = c;
			c = c->left;
		}
		return p;
	}

	rbnode<Data> * findright()
	{
		rbnode<Data> * p = 0;
		rbnode<Data> * c = this;
		while (c != 0)
		{
			p = c;
			c = c->right;
		}
		return p;
	}

	rbnode<Data> * succeed()
	{
		if (right != 0) return right->findleft();
		rbnode<Data> * p = parent;
		rbnode<Data> * c = this;
		while (p != 0 && p->left != c)
		{
			c = p;
			p = p->parent;
		}
		return p;
	}

	rbnode<Data> * preceed()
	{
		if (left != 0) return left->findright();
		rbnode<Data> * p = parent;
		rbnode<Data> * c = this;
		while (p != 0 && p->right != c)
		{
			c = p;
			p = p->parent;
		}
		return p;
	}
};

template <typename Data>
class rbtree_iterator : public std::iterator<std::bidirectional_iterator_tag, Data>
{
public:
	rbtree_iterator()
	: node(0)
	{}

	rbtree_iterator(rbnode<Data> * root)
	: node(root)
	{}

	Data const & operator*() const { return node->data; }
	Data const * operator->() const { return &node->data; }
	bool operator==(rbtree_iterator<Data> const & it) const { return node == it.node; }
	bool operator!=(rbtree_iterator<Data> const & it) const { return !(*this == it); }

	rbtree_iterator operator++(int)
	{
		rbtree_iterator it(*this);
		operator++();
		return it;
	}

	rbtree_iterator & operator++()
	{
		node = node->succeed();
		return *this;
	}

	rbtree_iterator operator--(int)
	{
		rbtree_iterator it(*this);
		operator--();
		return it;
	}

	rbtree_iterator & operator--()
	{
		node = node->preceed();
		return *this;
	}
	
	rbnode<Data> * rbtree_node() const { return node; }

private:
	rbnode<Data> * node;
};

template <typename Data, typename Comp = std::less<Data> >
class rbtree
{
public:
	typedef rbtree_iterator<Data> const_iterator;

	rbtree()
	: root(0)
	, length(0)
	{}

	rbtree(Comp const & c)
	: root(0)
	, length(0)
	, cmp(c)
	{}

	template <typename FwdIterator>
	rbtree(FwdIterator const &b, FwdIterator const &e)
	: root(0)
	, length(0)
	{
		insert(b, e);
	}

	template <typename FwdIterator>
	rbtree(FwdIterator const &b, FwdIterator const &e, Comp const & c)
	: root(0)
	, length(0)
	, cmp(c)
	{
		insert(b, e);
	}

	template <typename Container>
	rbtree(Container const &c)
	: root(0)
	, length(0)
	{
		insert(c.begin(), c.end());
	}

	template <typename Container>
	rbtree(Container const &c, Comp const & cm)
	: root(0)
	, length(0)
	, cmp(cm)
	{
		insert(c.begin(), c.end());
	}

	virtual ~rbtree()
	{
		for (rbtree_iterator<Data> it = begin(); it != end();)
			it = erase(it);
	}

	template <typename Container>
	rbtree<Data, Comp> & operator=(Container const & c)
	{
		/* save in other tree */
		rbtree<Data, Comp> save_tree;
		save_tree.root = root;
		save_tree.length = length;
		root = 0;
		length = 0;
		/* tries to assign */
		try
		{
			insert(c.begin(), c.end());
		}
		catch (std::exception const & e)
		{
			/* if an failure occurred then clean */
			clear();
			/* and restore old tree */
			root = save_tree.root;
			length = save_tree.length;
			save_tree.root = 0;
			save_tree.length = 0;
			/* rethrow */
			throw;
		}
		/* else destructor of save_tree remove elements */

		return *this;
	}

	void clear()
	{
		for (rbtree_iterator<Data> it = begin(); it != end();)
			it = erase(it);
		root = 0;
		length = 0;
	}

	rbtree_iterator<Data> begin() const { return rbtree_iterator<Data>(root->findleft()); }
	rbtree_iterator<Data> end() const { return rbtree_iterator<Data>(); }

	template <typename FwdIterator>
	void insert(FwdIterator const &b, FwdIterator const &e)
	{
		for (FwdIterator it(b); it != e; ++it)
			insert(*it);
	}

	rbtree_iterator<Data> insert(Data const & val)
	{
		rbnode<Data> * new_node = new rbnode<Data>(val);
		insert_node(new_node);
		++length;
		return rbtree_iterator<Data>(new_node);
	}

	rbtree_iterator<Data> find(Data const & val) const
	{
		rbnode<Data> * c = root;
		while ( (c != 0) && (c->data != val) )
		{
			if ( cmp(val, c->data) ) c = c->left;
			else c = c->right;
		}
		return rbtree_iterator<Data>(c);
	}

	rbtree_iterator<Data> erase(rbtree_iterator<Data> const &it)
	{
		rbnode<Data> * node = it.rbtree_node();
		if (!node)
			throw std::invalid_argument("erase called with end iterator\n");
		/* red black tree deletion takes O(log n) so test can't make it worth */
		if ( !contains_node(node) )
			throw std::invalid_argument("erase called with foreign iterator\n");

		rbtree_iterator<Data> next(it);
		++next;
		delete_node(node);
		--length;
		return next;
	}

	bool empty() const { return root == 0; }
	size_t size() const { return length; }



private:
	rbnode<Data> * root;
	size_t length;
	Comp cmp;

	bool contains_node(rbnode<Data> const * const node) const
	{
		rbnode<Data> * c = root;
		while ( (c != 0) && (c != node) )
		{
			if ( cmp(node->data, c->data) ) c = c->left;
			else c = c->right;
		}

		return c == node;
	}

	void left_rotate(rbnode<Data> * x)
	{
		rbnode<Data> * y = x->right;
		x->right = y->left;
		if (y->left) y->left->parent = x;
		if (y) y->parent = x->parent;
		if (x->parent)
		{
			if (x == x->parent->left) x->parent->left = y;
			else x->parent->right = y;
		}
		else
		{
			root = y;
		}
		y->left = x;
		if (x) x->parent = y;
	}

	void right_rotate(rbnode<Data> * x)
	{
		rbnode<Data> * y = x->left;
		x->left = y->right;
		if (y->right) y->right->parent = x;
		if (y) y->parent = x->parent;
		if (x->parent)
		{
			if (x == x->parent->right) x->parent->right = y;
			else x->parent->left = y;
		}
		else
		{
			root = y;
		}
		y->right = x;
		if (x) x->parent = y;
	}

	void insert_node(rbnode<Data> * node)
	{
		if (root == 0)
		{
			root = node;
			root->red = false;
			return;
		}
		else
		{
			rbnode<Data> * p = 0;
			rbnode<Data> * c = root;
			while (c != 0)
			{
				p = c;
				if ( cmp(node->data, c->data) ) c = c->left;
				else c = c->right;
			}
			if ( cmp(node->data, p->data) ) p->left = node;
			else p->right = node;
			node->parent = p;
		}
		insertFixup(node);
	}

	void insertFixup(rbnode<Data> * node)
	{
		while (node->parent && node->parent->red)
		{
			if (node->parent == node->parent->parent->left)
			{
				rbnode<Data> * y = node->parent->parent->right;
				if ( (y != 0) && (y->red) )
				{
					node->parent->red = false;
					y->red = false;
					node->parent->parent->red = true;
					node = node->parent->parent;
				}
				else
				{
					if (node == node->parent->right)
					{
						node = node->parent;
						left_rotate(node);
					}
					node->parent->red = false;
					node->parent->parent->red = true;
					right_rotate(node->parent->parent);
				}
			}
			else
			{
				rbnode<Data> * y = node->parent->parent->left;
				if ( (y != 0) && (y->red) )
				{
					node->parent->red = false;
					y->red = false;
					node->parent->parent->red = true;
					node = node->parent->parent;
				}
				else
				{
					if (node == node->parent->left)
					{
						node = node->parent;
						right_rotate(node);
					}
					node->parent->red = false;
					node->parent->parent->red = true;
					left_rotate(node->parent->parent);
				}
			}
		}
		root->red = false;
	}

	void delete_node(rbnode<Data> * node)
	{
		rbnode<Data> * y = 0;
		rbnode<Data> * x = 0;

		if (!node->left || !node->right) y = node;
		else y = node->right->findleft();

		if (y->left) x = y->left;
		else x = y->right;

		if (x) x->parent = y->parent;
		if (y->parent)
		{
				if (y == y->parent->left) y->parent->left = x;
				else y->parent->right = x;
		}
		else
		{
			root = x;
		}
		if (y != node)
		{
			y->parent = node->parent;
			y->left = node->left;
			y->right = node->right;
			if (node->parent)
			{
				if (node == y->parent->left) y->parent->left = y;
				else y->parent->right = y;
			}
			if (y->left) y->left->parent = y;
			if (y->right) y->right->parent = y;
		}

		if (!y->red) deleteFixup(x);
		delete node;
	}

	void deleteFixup(rbnode<Data> * node)
	{
		while (node && node != root && !node->red)
		{
			if (node == node->parent->left)
			{
				rbnode<Data> * w = node->parent->right;
				if (w && w->red)
				{
					w->red = false;
					w->parent->red = true;
					left_rotate(node->parent);
					w = node->parent->right;
				}
				if ( (!w->left || !w->left->red) && (!w->right || !w->right->red) )
				{
					w->red = true;
					node = node->parent;
				}
				else
				{
					if (!w->right || !w->right->red)
					{
						w->left->red = false;
						w->red = true;
						right_rotate(w);
						w = node->parent->right;
					}
					w->red = node->parent->red;
					node->parent->red = false;
					w->right->red = false;
					left_rotate(node->parent);
					node = root;
				}
			}
			else
			{
				rbnode<Data> * w = node->parent->left;
				if (w && w->red)
				{
					w->red = false;
					node->parent->red = true;
					right_rotate(node->parent);
					w = node->parent->left;
				}
				if ( (!w->left || !w->left->red) && (!w->right || !w->right->red) )
				{
					w->red = true;
					node = node->parent;
				}
				else
				{
					if (!w->left || !w->left->red)
					{
						w->right->red = false;
						w->red = true;
						left_rotate(w);
						w = node->parent->left;
					}
					w->red = node->parent->red;
					node->parent->red = false;
					w->left->red = false;
					right_rotate(node->parent);
					node = root;
				}
			}
		}
		if (node) node->red = false;
	}
};

#endif /* __RB_TREE_H__ */
