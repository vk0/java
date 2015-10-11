#ifndef STACK_2_H_
#define STACK_2_H_

#include <cassert>

template <class ValueType, class BackEnd>
class Stack {
	public:
		void push(const ValueType &i) {
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
		BackEnd mem_;   //проблема: при использовании требуется обеспечить совместимость хранилища BackEnd с типом ValueType
};

#endif