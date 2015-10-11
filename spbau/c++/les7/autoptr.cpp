#include <cstdlib>
#include "autoptr.h"

auto_ptr::auto_ptr(object *p) : ptr(p)
	{}

auto_ptr::~auto_ptr()
{
	delete ptr;
}

auto_ptr::auto_ptr(auto_ptr &a) : ptr(a.ptr)
{
	a.ptr = NULL;
}

bool auto_ptr::is_null()
{
	return ptr == NULL;
}

auto_ptr & auto_ptr::operator=(auto_ptr &a)
{
	if (this != &a) {
		ptr = a.ptr;
		a.ptr = NULL;
	}

	return *this;
}

object * auto_ptr::operator->()
{
	return ptr;
}

object & auto_ptr::operator*()
{
	return *ptr;
}
