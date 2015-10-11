#ifndef __FIB1_H__
#define __FIB1_H__

#include <assert.h>

unsigned long fib2(int n)
{
	unsigned long holder = 1, fib = 1, fnm1 = 0;

	assert(n >= 0);

	if (n == 0) return 0;
	if (n == 1) return 1;

	while(--n>0)
	{
		holder = fib;
		fib += fnm1;
		fnm1 = holder;
	}

	return fib;
}

#endif
