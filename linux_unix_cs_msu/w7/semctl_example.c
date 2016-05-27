// Рассмотрим программу, которая проиллюстрирует работу с массивами семафоров и с
// сегментом разделяемой памяти.
// Программа порождает два процесса, которые обмениваются друг с другом целым чис-
// лом. Первый процесс получает от второго некоторое число, печатает, увеличивает его на 1
// и отправляет обратно второму процессу и наоборот. Для пересылки значения числа исполь-
// зуется сегмент разделяемой памяти, а для синхронизации процессов — массив бинарных
// семафоров. Программа корректно освобождает занятые ресурсы.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <signal.h>
#define FTOK_FILE "sem14_2"
#define FTOK_PROJ 0
key_t ipc_key;
int shm_id = -1;
int sem_id = -1;
int *mem_ptr = (void *) - 1;
int pid[2] = { -1, -1 };
/* функция освобождает все занятые ресурсы */
void cleanup(void)
{
    if (pid[0] > 0) kill(pid[0], SIGTERM);
    if (pid[1] > 0) kill(pid[1], SIGTERM);
    if (mem_ptr != (void*) - 1) shmdt(mem_ptr);
    if (sem_id >= 0) semctl(sem_id, 0, IPC_RMID);
    if (shm_id >= 0) shmctl(shm_id, IPC_RMID, 0);
}
/* обработчик сигналов завершения программы */
void handler(int signo)
{
    exit(0);
}
void pexit(char const *str)
{
    perror(str);
    exit(1);
}
void do_work(int read_ind, int write_ind)
{
// операции, выполняемые при ожидании: ждем появления 0 (открыто)
// на семафоре данного процесса, сразу же устанавливаем его
// в 1 (закрыто)
    struct sembuf wait_ops[] = {{ -1, 0, 0 }, { -1, 1, 0}};
// операция при разблокировании: семафор должен быть
// установлен в 1, тогда переустанавливаем его в 0
    struct sembuf unlock_ops[] = {{ -1, -1, 0 }};
    sigset_t s, os;
    sigfillset(&s);
    wait_ops[0].sem_num = read_ind;
    wait_ops[1].sem_num = read_ind;
    unlock_ops[0].sem_num = write_ind;
    while (1) {
// блокируем сигналы завершения на время ожидания и печати
        sigprocmask(SIG_BLOCK, &s, &os);
// ожидаем
        if (semop(sem_id, wait_ops, 2) < 0) break;
        printf("%d: %d\n", getpid(), *mem_ptr);
        fflush(stdout);
        (*mem_ptr)++;
// разблокируем другой процесс
        if (semop(sem_id, unlock_ops, 1) < 0) break;
// разблокируем сигналы
        sigprocmask(SIG_SETMASK, &os, NULL);
    }
}
int main(void)
{
    int i;
// регистрируем функцию, которая будет автоматически вызываться
// при завершении программы с помощью exit() или
// return из функции main
    atexit(cleanup);
// устанавливаем обработчики сигналов
    signal(SIGINT, handler);
    signal(SIGTERM, handler);
    signal(SIGALRM, handler);
    signal(SIGHUP, handler);
// получаем и инициализируем разделяемую память
    ipc_key = ftok(FTOK_FILE, FTOK_PROJ);
    printf("Key = %d\n", ipc_key);
    if ((shm_id = shmget(ipc_key, sizeof(int), IPC_CREAT | IPC_EXCL | 0600)) < 0)
        pexit("shmget");
    mem_ptr = shmat(shm_id, NULL, 0);
    if (mem_ptr == (void*) - 1)
        pexit("shmat");
    *mem_ptr = 0;
// получаем семафоры
    if ((sem_id = semget(ipc_key, 2, IPC_CREAT | IPC_EXCL | 0600)) < 0)
        pexit("semget");
// значение семафора [0] - 0 (открыт), [1] - 1 (закрыт)
    if (semctl(sem_id, 1, SETVAL, 1) < 0)
        pexit("semctl");
    for (i = 0; i < 2; i++) {
        pid[i] = fork();
        if (pid[i] < 0) pexit("fork");
        if (!pid[i]) {
// сыновние процессы не выполняют никаких особенных действий
// при завершении работы, поэтому обработчики сбрасываются
            signal(SIGINT, SIG_DFL);
            signal(SIGTERM, SIG_DFL);
            signal(SIGALRM, SIG_DFL);
            signal(SIGHUP, SIG_DFL);
            do_work(i, 1 - i);
            _exit(1);
        }
    }
    alarm(5);
    wait(0); wait(0);
    return 0;
}