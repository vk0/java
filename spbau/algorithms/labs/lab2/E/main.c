#include <stdio.h>

static int numbers[1000];
static int lengths[1000];
static int size = 0;
static int maxlen = 0;
static int minval;

void init()
{
	int i;

	scanf("%d", &size);
	for (i = 0; i < size; i++) {
		scanf("%d", numbers+i);
		lengths[i] = 1;
	}
}

void printresults()
{
	int i, len = maxlen, last = minval-1;

	for (i = 0; i < size; i++) {
		if (lengths[i] == len && numbers[i] > last) {
			len--;
			printf("%d ", numbers[i]);
		}
	}
}

int findmax(int pos, int val) {
	int i;
	int max = 0;

	for (i = pos+1; i < size; i++)
		if (lengths[i] > max && numbers[i] > val)
			max = lengths[i];

	return max;
}

void process()
{
	int i, len;

	for (i = size-2; i >= 0; i--) {
		len = findmax(i, numbers[i]);
		lengths[i] = len+1;
		if (lengths[i] > maxlen) {
			minval = numbers[i];
			maxlen = lengths[i];
		}
	}
}

int main()
{
	init();
	process();
	printresults();

	return 0;
}
