#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstddef>
#include <cassert>

class Array {
	private:
		int * buffer;
		size_t size;

	public:
		Array(size_t size);
		~Array();
		Array(const Array &obj);
		Array & operator= (const Array & obj);

		int get(size_t index) const;
		void set(size_t index, int value);
		size_t getsize() const;
};

#endif /* _ARRAY_H_ */
