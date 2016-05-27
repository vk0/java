// Рассмотрим простейшую программу -клиент, которая открывает соединение на заданный
// адрес и порт и посылает текущее время. После этого программа ожидает получения текущего
// времени сервера, печатает его и завершает работу.
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
    int port, n, sfd;
    struct hostent *phe;
    struct sockaddr_in sin;
    time_t t;
    if (argc != 3) {
        fprintf(stderr, "Too few parameters\n");
        exit(1);
    }
    /* получим адрес компьютера */
    if (!(phe = gethostbyname(argv[1]))) {
        fprintf(stderr, "Bad host name: %s\n", argv[1]);
        exit(1);
    }
    /* прочитаем номер порта */
    if (sscanf(argv[2], "%d%n", &port, &n) != 1
            || argv[2][n] || port <= 0 || port > 65535) {
        fprintf(stderr, "Bad port number: %s\n", argv[2]);
        exit(1);
    }
    /* создаём сокет */
    if ((sfd = socket(PF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    /* для нашего клиента привязка сокета не важна,
    поэтому bind пропускаем */
    /* устанавливаем адрес подключения */
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port);
    memcpy(&sin.sin_addr, phe->h_addr_list[0], sizeof(sin.sin_addr));
    /* подсоединяемся к серверу */
    if (connect(sfd, (struct sockaddr*) &sin, sizeof(sin)) < 0) {
        perror("connect");
        exit(1);
    }
    /* отсылаем текущее время */
    t = time(0);
    t = htonl(t);
    /* желательно проверять результат write */
    write(sfd, &t, sizeof(t));
    /* считываем время сервера */
    if (read(sfd, &t, sizeof(t)) != sizeof(t)) {
        fprintf(stderr, "read failed\n");
    } else {
        printf("Server time: %s", ctime(&t));
    }
    /* закрываем сокет */
    close(sfd);
    return 0;
}
