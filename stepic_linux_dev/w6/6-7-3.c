// UDP log service

// Разработайте UDP сервер для логирования (сбора и записи) сообщений. Сервер при запуске принимает параметр -- номер порта, на котором будут приниматься запросы. Каждый запрос приходящий к серверу - строка, не превышающая размер 5K, заканчивающаяся нулевым символом.  Задача сервера -- выводить приходящие строки в стандартный поток ввода-вывода, завершающиеся символом конца строки.

// Сервер завершает работу, когда получает строку содержащую только текст 'OFF'.

// Сервер использует локальный адрес 127.0.0.1

// Пример вызова

// ./solution 22476
// foo
// bar
// foo bar baz


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток строки, причем каждая строка должна оканчиваться символом конца строки.

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

#define BUFSIZE 10000

int main(int argc, char* argv[])
{
    struct sockaddr_in local;
    char buf[BUFSIZE];
    int res;
    int s;
    int i = 0;

    if (argc != 2)
        return -1;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(argv[1]));
    local.sin_family = AF_INET;

    bind(s, (struct sockaddr*) &local, sizeof(local));

    while (1)
    {
        res = read(s, buf, BUFSIZE);
        if (strncmp(buf, "OFF", 3) == 0)
        {
            break;
        }
        printf("%s\n", buf);
    }
    close(s);
    return 0;
}