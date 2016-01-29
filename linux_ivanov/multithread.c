#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
void * thread_func1 (void * arg)
{
    fprintf (stderr, "thread1: %s\n", (char*) arg);
    sleep (5);
    return NULL;
}
void * thread_func2 (void * arg)
{
    fprintf (stderr, "thread2: %s\n", (char*) arg);
    sleep (5);
    return NULL;
}
int main (void)
{
pthread_t thread1, thread2;
char * thread1_str = "Thread1";
char * thread2_str = "Thread2";

if (pthread_create (&thread1, NULL,&thread_func1, thread1_str) != 0) {
    fprintf (stderr, "Error (thread1)\n");
    return 1;
}

if (pthread_create (&thread2, NULL,&thread_func2, thread2_str) != 0) {
    fprintf (stderr, "Error (thread2)\n");
    return 1;
}

fprintf (stderr, "Hello World\n");
    while (1);
    return 0;
}