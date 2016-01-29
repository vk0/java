#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void * any_func (void * args)
{
    fprintf (stderr, "Hello World\n");
    sleep (5);
    return NULL;
}
int main (void)
{
    pthread_t thread;
    int result;

    result = pthread_create(&thread, NULL, &any_func, NULL);

    if (result != 0) {
        fprintf (stderr, "Error\n");
        return 1;
}
    fprintf (stderr, "Goodbye World\n");
    while (1);
    return 0;
}