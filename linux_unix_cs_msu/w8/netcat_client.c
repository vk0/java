// В качестве примера рассмотрим программу, которая открывает соединение с заданным
// компьютером и заданным портом, а затем копирует всё, что поступает со стандартного пото -
// ка ввода, в сокет, и всё, что поступает с сокета, на стандартный поток вывода.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
int main(int argc, char const *argv[])
{
    int port, n, sfd, sz;
    struct hostent *phe;
    struct sockaddr_in sin;
    fd_set fds;
    char buf[256];
    if (argc != 3) {
        fprintf(stderr, "Too few parameters\n");
        exit(1);
    }
    if (!(phe = gethostbyname(argv[1]))) {
        fprintf(stderr, "Bad host name: %s\n", argv[1]);
        exit(1);
    }
    if (sscanf(argv[2], "%d%n", &port, &n) != 1
            || argv[2][n] || port <= 0 || port > 65535) {
        fprintf(stderr, "Bad port number: %s\n", argv[2]);
        exit(1);
    }
    if ((sfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    memcpy(&sin.sin_addr, phe->h_addr_list[0], sizeof(sin.sin_addr));
    if (connect(sfd, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
        perror("connect");
        exit(1);
    }
    while (1) {
        FD_ZERO(&fds);
        FD_SET(sfd, &fds);
        FD_SET(0, &fds);
        if (select(FD_SETSIZE, &fds, NULL, NULL, NULL) <= 0) {
            perror("select");
            exit(1);
        }
        if (FD_ISSET(sfd, &fds)) {
            /* надо бы проверять на ошибки */
            sz = read(sfd, buf, sizeof(buf));
            if (!sz) break;
            write(1, buf, sz);
        }
        if (FD_ISSET(0, &fds)) {
            /* надо бы проверять на ошибки */
            sz = read(0, buf, sizeof(buf));
            if (!sz) break;
            write(sfd, buf, sz);
        }
    }
    close(sfd);
    return 0;
}