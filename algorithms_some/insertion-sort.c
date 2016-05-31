#include <stdio.h>

#define LEN 20

int insertion_sort(int *array, int n)
{
	--n; /* considering that n is the real size of elements */

	if (n < 1)
		return -1;

	for (int i = 1; i <= n; ++i) {
		int tmp = array[i]; /* save the current value */
		int prev;

		/*
		 * move elements that are greater than current value
		 * one position ahead
		 */
		for (prev = i - 1; prev >= 0 && array[prev] > tmp; --prev)
			array[prev + 1] = array[prev];

		/* save current value to sorted position */
		array[prev + 1] = tmp;
	}

	return 0;
}

int main(void)
{
	int array[LEN] = {3, 1, 4, 7, 10,
			  20, 17, 19, 15, 16,
			  18, 2, 5, 6, 8,
			  9, 11, 13, 12, 14};

	insertion_sort(array, LEN);

	for (int i = 0; i < LEN; ++i)
		printf("%d ", array[i]);

	return 0;
}
