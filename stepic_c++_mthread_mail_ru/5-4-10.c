// Задача на именованные каналы.

// Напишите программу, которая создает два именованных канала - /home/box/in.fifo и /home/box/out.fifo

// Пусть программа читает in.fifo и все прочитанное записывает в out.fifo.

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF 1024
char buf[1024];

int main()
{
    char * outfifo = "/home/box/out.fifo";
    char * infifo = "/home/box/in.fifo";

    /* create the FIFO (named pipe) */
    mkfifo(infifo, 0666);
    mkfifo(outfifo, 0666);

    int outfd = open(outfifo, O_WRONLY);
    int infd = open(infifo, O_RDONLY);

    for (;;)
    {
       int got = read(infd, buf, MAX_BUF);
       write (outfd, buf, got);
    }


    close(outfd);
    close (infd);

    /* remove the FIFO */
    unlink(infifo);
    unlink(outfifo);

    return 0;
}