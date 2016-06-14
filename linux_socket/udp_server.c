#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(void)
{
    struct sockaddr_in serv_addr, clnt_addr;

    int s, i, slen = sizeof(clnt_addr), nbytes;
    char buf[256];

    if ((s = socket(PF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Ошибка вызова socket()");
        exit(1);
    }

    /* Очистка памяти структуры serv_addr. */
    memset((char *) &serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    /* Привязка сокета к прослушиваемому порту и адресу. */
    if ( bind(s , (struct sockaddr*)&serv_addr, sizeof(serv_addr) ) == -1)
    {
        perror("Ошибка вызова bind()");
        exit(2);
    }

    /* Принимаем входящие соединения. */
    while (1)
    {
        printf("Ждём подключения.\n");
        fflush(stdout);

        if ((nbytes = recvfrom(s, buf, sizeof(buf) - 1, 0, (struct sockaddr *) &clnt_addr, &slen)) == -1)
        {
            perror("Ошибка вызова recvfrom()");
            exit(3);
        }

        buf[nbytes] = '\0';
        printf("Дейтаграмма от %s:%d\n", inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));
        printf("Её содержимое: %s\n", buf);

    }

    close(s);
    return 0;
}
