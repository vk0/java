#ifndef __FIB1_H__
#define __FIB1_H__

#include <assert.h>

unsigned long fib1(int n)
{
	assert(n >= 0);

	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib1(n-1)+fib1(n-2);
}

#endif
