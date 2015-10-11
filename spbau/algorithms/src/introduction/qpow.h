#ifndef __QPOW_H__
#define __QPOW_H__

long int qpow(int number, unsigned int power)
{
	int res = 1, temp = number;

	while (power) {
		if (power % 2) res *= temp;
		if (power >>= 1) temp *= temp;
	}

	return res;
}

#endif

