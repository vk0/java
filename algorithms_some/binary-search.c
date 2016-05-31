#include <stdio.h>

int binary_search(int *arr, int n, int key)
{
	--n; /* considering that n is the real size of elements */

	if (n < 1)
		return -1;

	int first = 0, last = n;

	while (first <= last) {
		/* always divide by 2 reducing the searchable area */
		int middle = (first + last) >> 1;

		if (arr[middle] == key)
			return middle;

		/* rearrange searchable area */
		if (arr[middle] > key)
			last = middle - 1;
		else
			first = middle + 1;
	}

	return -1;
}


int main(void)
{
	int tab[100];

	for (int i = 0; i < 100; ++i) {
		tab[i] = i;
	}

	printf("Index: %d\n", binary_search(tab, 100, 68));

	return 0;
}
