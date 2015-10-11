#ifndef STACK_1_H_
#define STACK_1_H_

#include <vector>
#include <cassert>

template <class T>
class Stack {
	public:
		void push(const T& i) {
			vec_.push_back(i);
		}
		
		T pop() {
			assert(!vec_.empty());
			
			T temp = vec_.back();
			vec_.pop_back();
			
			return temp;
		}
		
		bool empty() const {
			return vec_.empty();
		}
		
	private:
		std::vector<T> vec_; //а что, если мы хотим использовать другое хранилище для реализации стека? - сделаем его параметром шаблона
};

#endif