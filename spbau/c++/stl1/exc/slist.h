#ifndef _SLIST_H_
#define _SLIST_H_

#include <cassert>

template <class T>
struct slist_node {
	struct slist_node *m_next;
	T m_data;

	slist_node(const T &data, struct slist_node *next = 0) : m_data(data), m_next(next)
	{}
	
	struct slist_node* push_front(const T &data) {
		return new slist_node(data, this);
	}
	
	T& get() {
		return m_data;
	}
	
	const T& get() const {
		return m_data;
	}
	
	struct slist_node *next() const {
		return m_next;
	}
};

template <class T>
class slist_iterator {
	private:
		struct slist_node<T> *m_next;
	public:
		slist_iterator(struct slist_node<T> * next = 0) : m_next(next)
		{}

		slist_iterator<T> &operator++() {
			assert(m_next != 0);
			
			m_next = m_next->next();
			return *this;
		}
		
		slist_iterator<T> operator++(int) {
			assert(m_next != 0);
			
			slist_iterator temp(*this);
			++(*this);
			return temp;
		}
		
		T &operator*() {
			assert(m_next != 0);
			
			return m_next->get();
		}
		
		T* operator->() {
			assert(m_next != 0);
			
			return &(m_next->get());
		}
		
		bool operator==(slist_iterator<T> it) {
			return it.m_next == m_next;
		}
		
		bool operator!=(slist_iterator<T> it) {
			return !(it == *this); 
		}
};

template <class T>
class slist {
	private:
		typedef struct slist_node<T> node;
		node *m_first;
		size_t m_size;
	public:
		typedef slist_iterator<T> iterator;
	
		slist() : m_first(0), m_size(0)
		{}
		
		~slist() {
			node *curr = 0;
			while (m_first != 0) {
				curr = m_first;
				m_first = m_first->next();
				delete curr;
			}
		}
		
		size_t size() const {
			return m_size;
		}
		
		bool isempty() const {
			return m_size == 0;
		}
		
		void push_front(const T &obj) {
			if (isempty()) {
				m_first = new node(obj);
				m_size = 1;
			} else {
				m_first = m_first->push_front(obj);
				m_size++;
			}
		}
		
		T front() {
			assert(!isempty());
			
			return m_first->get();
		}
		
		void pop() {
			assert(!isempty());
			
			node *d = m_first;
			m_first = m_fisrt->next();
			m_size--;
			delete d;
		}
		
		iterator begin() {
			return iterator(m_first);
		}
		
		iterator end() {
			return iterator(0);
		}
};

#endif //_SLIST_H_