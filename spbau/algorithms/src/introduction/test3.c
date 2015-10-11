#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

#include "fib3.h"

int main(int argc, char **argv)
{
	int i, n;
	char *tail;

	assert(argc > 1);

	for(i = 1; i < argc; i++) {
		n = strtol(*(argv+i), &tail, 10);
		assert((!errno)&&(*tail == '\0'));
		printf("F(%d) = %lu\n", n, fib3(n));
	}	

	return 0;
}
