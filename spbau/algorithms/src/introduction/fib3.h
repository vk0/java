#ifndef __FIB1_H__
#define __FIB1_H__

#include <assert.h>

#include "m2x2.h"
#include "qpowm.h"

unsigned long fib3(int n)
{
	struct m2x2 m;

	assert(n >= 0);

	if (n == 0) return 0;
	if (n == 1) return 1;

	m.a11 = 1; m.a12 = 1;
	m.a21 = 1; m.a22 = 0;

	qpowm(&m, &m, n-1);

	return m.a11;
}

#endif
