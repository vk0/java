#include "object.h"
#include "autoptr.h"

int main()
{
	auto_ptr p1(new object());
	auto_ptr p2 = p1;
	auto_ptr p3;
	p3 = p2;

	p3->foo();
	(*p3).foo();
	return 0;
}
