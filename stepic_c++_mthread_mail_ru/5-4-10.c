// Задача на именованные каналы.

// Напишите программу, которая создает два именованных канала - /home/box/in.fifo и /home/box/out.fifo

// Пусть программа читает in.fifo и все прочитанное записывает в out.fifo.


#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define IN_FIFO "/home/box/in.fifo"
#define OUT_FIFO "/home/box/out.fifo"
#define MAX_BUF 2048

int main()
{
    mkfifo(IN_FIFO, 0666);
    mkfifo(OUT_FIFO, 0666);

    int infd = open(IN_FIFO, O_RDONLY);
    perror("Error after infd open: ");
    int outfd = open(OUT_FIFO, O_WRONLY);
    perror("Error after outfd open: ");


    char buf[MAX_BUF];
    int got;
    while ( got = read(infd, buf, MAX_BUF) ) {
        printf("Read: %s\n", buf);
        write(outfd, buf, got);
        memset(buf, 0, 12);
    }

    close(outfd);
    close(infd);
    unlink(IN_FIFO);
    unlink(OUT_FIFO);

    return 0;
}