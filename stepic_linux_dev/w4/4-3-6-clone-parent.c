#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


#define STACK_SIZE 10000
char child_stack[STACK_SIZE+1];

int child(void *params)
{
    int c=0;
    while(true)
    {
        usleep(50000);
        printf("child turn%d\n", c++);
    }
}

int main()
{
    int c=0;
    int result = clone(child, child_stack+STACK_SIZE,CLONE_PARENT,0);
    printf("clone result = %d\n", result);

    while(true)
    {
        usleep(50000);
        printf("parent turn %d\n", c++);
    }
}