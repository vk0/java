#include "array.h"

Array::Array(size_t size) : buffer(NULL), size(size)
{
	buffer = new int[size];
	assert(buffer != NULL);
}

Array::~Array()
{
	delete[] buffer;
}

Array::Array(const Array &obj) : size(obj.size)
{
	buffer = new int[size];

	for (size_t i = 0; i < size; i++)
		buffer[i] = obj.buffer[i];
}

Array & Array::operator=(const Array &obj)
{
	if (&obj != this) {
		size = obj.size;
		delete[] buffer;
		buffer = new int[size];
		for (size_t i = 0; i < size; i++)
			buffer[i] = obj.buffer[i];
	}

	return *this;
}

int Array::get(size_t index) const
{
	assert(index < size);
	return buffer[index];
}

void Array::set(size_t index, int value)
{
	assert(index < size);
	buffer[index] = value;
}

size_t Array::getsize() const
{
	return size;
}
