#include <stdio.h>

#define LEN 20

int sentinel_linear_search(int key, int *arr, int n)
{
	int last_value, i;

	/* considering that n is the real size of the array */
	if (--n < 1)
		return -1;

	last_value = arr[n];

	/* set array last member as the key */
	arr[n] = key;

	i = 0;
	while (arr[i] != key)
		++i;

	/* recover the real array last member */
	arr[n] = last_value;

	return (arr[i] == key) ? i : -1;
}


int main(void)
{
	int array[LEN] = {3, 1, 4, 7, 10,
			  20, 17, 19, 15, 16,
			  18, 2, 5, 6, 8,
			  9, 11, 13, 12, 14};

	printf("Index: %d\n", sentinel_linear_search(14, array, LEN));

	return 0;
}
