#include <stdio.h>

static char string[5000];
static int k = 0;
static int len = 0;

void init()
{
	scanf("%d %d\n%s", &len, &k, string);
}

int countfrom(int left, int right)
{
	int errors = 0, count = 0;

	while (left >= 0 && right < len) {
		if (string[left] != string[right]) {
			errors++;
			if (errors > k) break;
		}
		left--;
		right++;
		count++;
	}

	return count;
}

long parity()
{
	int i;
	long sum = 0;

	for (i = 1; i < len; i++)
		sum += countfrom(i-1, i);

	return sum;
}

long noparity()
{
	int i;
	long sum = 0;

	for (i = 0; i < len; i++)
		sum += countfrom(i-1, i+1);
	sum += len;

	return sum;
}

void process()
{
	printf("%ld", parity()+noparity());
}

int main()
{
	init();
	process();

	return 0;
}
