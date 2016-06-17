// Тренировочная задача.

// Создайте пару сокетов, соединяющую два процесса (файл с исходниками должен быть один и находиться в /home/box/work.cpp). Процесс должен быть запущен.

// [Не оценивается] Потренируйтесь передавать дескрипторы через эту пару сокетов.

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>

void child(int socket) {
    const char hello[] = "I am your child, Wherever you go, You take me too, Whatever I knowm I learned from you";
    write(socket, hello, sizeof(hello));
    while (1);
}

void parent(int socket) {
    char buf[1024];
    int n = read(socket, buf, sizeof(buf));
    printf("parent received '%.*s'\n", n, buf);
    while (1);
}

int main(int argc, char **argv) {
    int fd[2];
    static const int parentsocket = 0;
    static const int childsocket = 1;
    pid_t pid;

    socketpair(PF_LOCAL, SOCK_STREAM, 0, fd);
    pid = fork();
    if (pid == 0) {
        close(fd[parentsocket]);
        child(fd[childsocket]);
    } else {
        close(fd[childsocket]);
        parent(fd[parentsocket]);
    }
    return 0;
}