#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

// номер порта для приёма входящих соединений сервером
#define PORTNUM 1234

int main(void)
{

    int listen_s, connected_s, nbytes;
    struct sockaddr_in serv_addr, clnt_addr;
    char buf[256]; // буфер для приёма сообщения
    unsigned long addr;

    if ( (listen_s = socket(PF_INET, SOCK_STREAM, 0) ) == -1 )
    {
        perror("Ошибка вызова socket()");
        exit(1);
    }

    /* Заполняем, предварительно обнулив, структуру serv_addr
    для описания «своего» конца коммуникационного канала:
    указываем семейство адресов AF_INET (то есть IP-адреса);
    входящий адрес сокета INADDR_ANY (0.0.0.0) означает
    принимать соединения на всех имеющихся у хоста адресах. */
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((u_short)PORTNUM);

    /* Связываем сокет listen_s с адресом и портом,
    содержащимися в serv_addr, определяя локальную часть
    коммуникационного канала. */
    if ( bind(listen_s, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1 )
    {
        perror("Ошибка вызова bind()");
        exit(2);
    }
    /* Переводим сокет в режим ожидания соединений – фактически
    в модуль TCP передаётся вызов PASSIVE_OPEN. Второй параметр
    задаёт максимальный размер, до которого может расти очередь
    ожидающих соединений у listen_s. */
    if ( listen(listen_s, 10) == -1 )
    {
        perror("Ошибка вызова listen()");
        exit(3);
    }

    printf("Сервер готов принимать соединения\n");

    /* Обнуляем структуру clnt_addr, в которую будут записаны
    адрес и порт подсоединившегося клиента. */
    int addrlen;
    bzero(&clnt_addr, sizeof(clnt_addr));
    addrlen = sizeof(clnt_addr);

    /* Принимаем запрос. Возврат из функции accept()
    производится только после поступления запроса
    и установления соединения с клиентом. При этом на базе
    старого сокета listen_s создаётся новый сокет connected_s,
    у которого определены уже обе части соединения – локальная
    и удалённая. Таким образом, сокет connected_s уже может
    использоваться для передачи данных. Адрес и порт
    подсоединившегося клиента возвращаются в структуре
    clnt_addr. */

    if ( (connected_s = accept(listen_s, (struct sockaddr *)&clnt_addr, &addrlen) ) == -1 )
    {
        perror("Ошибка вызова accept()");
        exit(4);
    }

    printf("Соединение от %s\n", inet_ntoa(clnt_addr.sin_addr));

    nbytes = recv(connected_s, buf, sizeof(buf) - 1, 0);
    if (nbytes > 0)
    {
        buf[nbytes] = '\0';
        printf("Получено сообщение: %s\n", buf);
    }

    printf("Завершаем работу, закрываем сокет.\n");
    close(connected_s);
    close(listen_s);
    exit(0);
}