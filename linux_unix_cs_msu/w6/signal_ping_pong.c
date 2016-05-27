// Рассмотрим следующую программу. Два процесса обмениваются друг с другом сообще -
// ниями в стиле пинг -понг, то есть первый посылает второму число 1, на что второй отвечает
// первому числом 2, и так далее. Для обмена данными используется единственный канал, а
// процессы синхронизуются посылкой друг другу сигнала SIGUSR1. Главный процесс поро -
// дит два подпроцесса, которые и будут обмениваться данными, а он сам будет просто ожидать
// завершения обоих процессов.
// Первая проблема, которая возникает, как передать каждому процессу идентификатор
// другого процесса. Мы обойдем ее поместив оба процесса в одну группу процессов. Каждый
// процесс будет посылать сигнал SIGUSR1 всей группе процессов.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
volatile int flag;
void handler(int signo)
{
    flag = 1;
}
void do_work(int pgid, int sig, int *p)
{
    sigset_t bs, os, b2;
    int val;
    sigemptyset(&bs);
    sigaddset(&bs, SIGUSR1);
    sigaddset(&bs, SIGUSR2);
    sigemptyset(&b2);
    sigaddset(&b2, SIGINT);
    sigaddset(&b2, SIGTERM);
    sigprocmask(0, NULL, &os);
    while (1) {
        /* ожидаем прихода либо SIGUSR1, либо SIGUSR2 */
        /* так как один из них игнорируется, мы всегда получим нужный */
        sigprocmask(SIG_BLOCK, &bs, NULL);
        while (!flag)
            sigsuspend(&os);
        flag = 0;
        sigprocmask(SIG_UNBLOCK, &bs, NULL);
        read(p[0], &val, sizeof(val));
        /* мы не хотим, чтобы нас прервали на середине печати */
        sigprocmask(SIG_BLOCK, &b2, NULL);
        printf("Process %d got value %d\n", getpid(), val);
        fflush(stdout);
        sigprocmask(SIG_UNBLOCK, &b2, NULL);
        val++;
        write(p[1], &val, sizeof(val));
        kill(-pgid, sig);
    }
}
int main(void)
{
    int pid1, pid2;
    int pgid;
    int p[2];
    int val = 0;
    pgid = getpid();
    signal(SIGUSR1, handler);
    signal(SIGUSR2, SIG_IGN);
    if (pipe(p) < 0) { perror("pipe"); exit(1); }
    if ((pid1 = fork()) < 0) { perror("fork"); exit(1); }
    if (!pid1) {
        setpgid(0, pgid);
        do_work(pgid, SIGUSR2, p);
        _exit(0);
    }
    setpgid(pid1, pgid);
    signal(SIGUSR1, SIG_IGN);
    signal(SIGUSR2, handler);
    if ((pid2 = fork()) < 0) { perror("fork"); exit(1); }
    if (!pid2) {
        setpgid(0, pgid);
        do_work(pgid, SIGUSR1, p);
        _exit(0);
    }
    setpgid(pid2, pgid);
    write(p[1], &val, sizeof(val));
    close(p[0]); close(p[1]);
    signal(SIGUSR2, SIG_IGN);
    kill(-pgid, SIGUSR1);
    sleep(1);
    signal(SIGTERM, SIG_IGN);
    kill(-pgid, SIGTERM);
    wait(0); wait(0);
    return 0;
}