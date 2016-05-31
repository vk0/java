#include <stdio.h>

#define LEN 20

int selection_sort(int *array, int n)
{
	--n; /* considering that n is the real size of elements */

	if (n < 1)
		return -1;

	for (int i = 0; i < n - 1; ++i) {
		int min = i;

		/* find next smallest */
		for (int j = i + 1; j <= n; ++j)
			if (array[j] < array[min])
				min = j;

		/* swap smallest with current value */
		if (min != i) {
			int tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
		}
	}

	return 0;
}

int main(void)
{
	int array[LEN] = {3, 1, 4, 7, 10,
			  20, 17, 19, 15, 16,
			  18, 2, 5, 6, 8,
			  9, 11, 13, 12, 14};

	selection_sort(array, LEN);

	for (int i = 0; i < LEN; ++i)
		printf("%d ", array[i]);

	return 0;
}
