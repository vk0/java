#ifndef STACK_3_H_
#define STACK_3_H_

#include <cassert>
#include <memory>  // template <class T> allocator
#include <vector>
#include <algorithm>

template <class T, template <class, class> class BackEnd = std::vector, template <class> class Allocator = std::allocator>
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

/*		
		template <class Copied>
		Stack(Copied stack) {
			while (!stack.empty())
				push(stack.pop());
			reverse(mem_.begin(), mem_.end());
		}
*/
		
		template <class U, template <class, class> class C, template <class> class A>
		Stack(Stack<U,C,A> stack) {
			while (!stack.empty())
				push(stack.pop());
			reverse(mem_.begin(), mem_.end());
		}
		
		Stack() : mem_() {} //констуктора по умолчанию уже не будет

	private:
		BackEnd<T, Allocator<T> > mem_;
};

template <class T, template <class, class> class BackEnd, template <class> class Allocator>
class Stack<T*, BackEnd, Allocator> {
	public:
		void push(const T *i) {
			mem_.push_back(i);
		}
		
		T *pop() {
			assert(!mem_.empty());
			T *temp = mem_.back();
			mem_.pop_back();
			
			return temp;
		}
		
		bool empty() const {
			return mem_.empty();
		}
		
		~Stack() {
			typename BackEnd<T*, Allocator<T*> >::iterator iterator = mem_.begin();
			while (iterator != mem_.end()) {
				delete (*iterator);
				iterator++;
			}
		}
		
	private:
		BackEnd<T*, Allocator<T*> > mem_;
};

#endif