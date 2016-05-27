// В качестве программы -сервера рассмотрим программу, которая ожидает подключения
// от клиента и считывает время клиента. Текущее время сервера пересылается клиенту. По -
// сле подключения клиента работа с клиентом ведётся в отдельном процессе. Это позволяет
// параллельно обслуживать несколько клиентов и принимать новые запросы.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <sys/wait.h>
#include <arpa/inet.h>
int main(int argc, char const *argv[])
{
    int lfd, n, port, afd, alen, sopt, pid;
    struct sockaddr_in baddr, aaddr;
    time_t ct, st;
    if (argc != 2) {
        fprintf(stderr, "Too few parameters\n");
        exit(1);
    }
    /* прочитаем номер порта */
    if (sscanf(argv[1], "%d%n", &port, &n) != 1
            || argv[1][n] || port <= 0 || port > 65535) {
        fprintf(stderr, "Bad port number: %s\n", argv[2]);
        exit(1);
    }
    /* создаём сокет */
    if ((lfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    /* задаём режим сокета */
    sopt = 1;
    if (setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &sopt, sizeof(sopt)) < 0) {
        perror("setsockopt");
        exit(1);
    }
    /* задаём адрес сокета */
    baddr.sin_family = AF_INET;
    baddr.sin_port = htons(port);
    baddr.sin_addr.s_addr = INADDR_ANY;
    /* привязываем сокет */
    if (bind(lfd, (struct sockaddr *) &baddr, sizeof(baddr)) < 0) {
        perror("bind");
        exit(1);
    }
    /* включаем режим прослушивания */
    if (listen(lfd, 5) < 0) {
        perror("listen");
        exit(1);
    }
    while (1) {
        /* хороним <<зомби>> */
        while (waitpid(-1, NULL, WNOHANG) > 0);
        /* ожидаем подключения */
        alen = sizeof(aaddr);
        if ((afd = accept(lfd, (struct sockaddr*) &aaddr, &alen)) < 0) {
            perror("accept");
            exit(1);
        }
        /* запросы клиентов будем обслуживать в другом процессе */
        if ((pid = fork()) < 0) {
            perror("fork");
        } else if (!pid) {
            close(lfd);
            /* печатаем информацию о подключении */
            printf("%d: Connection from %s:%d accepted.\n", getpid(),
                   inet_ntoa(aaddr.sin_addr), ntohs(aaddr.sin_port));
            if (read(afd, &ct, sizeof(ct)) != sizeof(st)) {
                fprintf(stderr, "read error\n");
            } else {
                /* печатаем время клиента и сервера */
                ct = ntohl(ct);
                st = time(0);
                printf("%d: Client time %lu, server time %lu\n",
                       getpid(), ct, st);
                st = htonl(st);
                /* желательно проверять результат write */
                write(afd, &st, sizeof(st));
            }
            close(afd);
            _exit(0);
        }
        close(afd);
    }
    return 0;
}