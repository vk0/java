#include <stdio.h>
#include <time.h>
#define N 500
main () {
int i;
int arr[5] = {0};
srand(time(NULL));
for (i=0; i < N; i++)
switch (rand() % 5) {
case 0: arr[0]++;break;
case 1: arr[1]++;break;
case 2: arr[2]++;break;
case 3: arr[3]++;break;
case 4: arr[4]++;break;
}
for (i=0; i < 5; i++)
printf("%d - %.2f%%\n", i, ((float) arr[i] / N) * 100);
}
