#ifndef __QPOW_M_H__
#define __QPOW_M_H__

#include "m2x2.h"

void qpowm(struct m2x2 *res, struct m2x2 *m, unsigned int power)
{
	struct m2x2 temp;

	copy(m, &temp);

	(*res).a11 = 1; (*res).a12 = 0;
	(*res).a21 = 0; (*res).a22 = 1;

	while (power) {
		if (power % 2) mul(res, &temp);
		if (power >>= 1) mul(&temp, &temp);
	}
}

#endif

