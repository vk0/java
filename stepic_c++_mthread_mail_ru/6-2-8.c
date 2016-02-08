// Создайте очередь сообщения SysV с ключем:

// key_t key = ftok("/tmp/msg.temp", 1);

// Тестовая среда пошлет в нее сообщение.

// struct message {
//     long mtype;
//     char mtext[80];
// }

// Получите его и сохраните в /home/box/message.txt

//sudo ./msgq_sysv

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <errno.h>

struct message {
    long mtype;
    char mtext[80];
};

int main()
{
    FILE *fd = fopen("/home/box/message.txt", "w");
    if (fd == NULL)
    {
        printf("Error opening a file: %d\n", errno);
        exit(1);
    }
    key_t key = ftok("/tmp/msg.temp", 1);
    int msg_id = msgget(key, IPC_CREAT | 0660);
    if (msg_id == -1)
    {
        printf("Error opening a message queue: %d\n", errno);
        exit(1);
    }
    struct message msg;

    int res = msgrcv(msg_id, &msg, sizeof(struct message) - sizeof(long), 0, 0);
    if (res == -1)
    {
        printf("Error reciving a message: %d\n", errno);
        exit(1);
    }
    printf("Recived %d\n", res);

    msg.mtext[res] = '\0';
    printf("Message: %s\n", msg.mtext);
    fprintf(fd, "%s\n", msg.mtext);
    fflush(fd);
    fclose(fd);
    printf("All is done!\n");
    return 0;
}
