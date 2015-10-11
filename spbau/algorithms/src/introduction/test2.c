#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#include "qpow.h"

int main(int argc, char **argv)
{
	int i, number, power;
	char *tail;

	assert((argc > 1)&&(argc % 2));

	for(i = 1; i < argc; i += 2) {
		number = (int)strtol(*(argv + i), &tail, 10);
		power = (int)strtol(*(argv + i + 1), &tail, 10);
		assert((!errno)&&(*tail == '\0'));
		printf("%d ^ %u = %ld\n", number, power, qpow(number, power));
	}	

	return 0;
}
