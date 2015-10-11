#include <stdio.h>
#include <pthread.h>

static int i = 0;

void *first(void* ptr)
{
	while (i<=100000) i++;
	printf("Process A is winner, and i = %d\n", i);
}

void *second(void* ptr)
{
	while (i>=-100000) i--;
	printf("Process B is winner, and i = %d\n", i);
}

int main()
{
	pthread_t A, B;
	char *winA = "thread A is winner";
	char *winB = "thread B is winner";
	int ret1, ret2;

	ret1 = pthread_create(&A, NULL, first, NULL);
	ret2 = pthread_create(&B, NULL, second, NULL);

	pthread_join(A, NULL);
	pthread_join(B, NULL);

	return 0;
}
