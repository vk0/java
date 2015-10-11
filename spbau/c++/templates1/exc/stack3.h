#ifndef STACK_3_H_
#define STACK_3_H_

#include <cassert>
#include <memory>  // template <class T> allocator
#include <vector>

template <class T, template <class, class Allocator = std::allocator<T> > class BackEnd = std::vector>
class Stack {
	public:
		void push(const T &i) {
			mem_.push_back(i);
		}
		
		T pop() {
			assert(!mem_.empty());
			
			T temp = mem_.back();
			mem_.pop_back();
			
			return temp;
		}
		
		bool empty() const {
			return mem_.empty();
		}

	private:
		BackEnd<T> mem_;
};

#endif