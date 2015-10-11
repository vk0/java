#ifndef __AUTO_PTR_H__
#define __AUTO_PTR_H__

#include "object.h"

class auto_ptr
{
private:
	object *ptr;

public:
	auto_ptr(object *p = 0);
	~auto_ptr();
	bool is_null();
	auto_ptr(auto_ptr &a);
	auto_ptr &operator=(auto_ptr &a);
	object *operator->();
	object &operator*();
};

#endif /* __AUTO_PTR_H__ */
