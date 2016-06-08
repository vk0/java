// Host resolver

// Разработайте утилиту командной строки, принимающую на вход имя хоста и печатающую в стандартный поток вывода список IP-адресов, ассоциированных с данным именем.

// Пример вызова

// ./solution yandex.ru
// 213.180.204.3
// 93.158.134.3
// 213.180.193.3


// Представление решения

// Решение предоставляется в виде двух файлов solution.c и Makefile, в последнем предполагается цель по умолчанию, которая приводит к сборке Вашего приложения. Бинарный файл вашего решения должен иметь имя solution.

// Вывод

// Программа выводит в стандартный поток вывода IP-адреса, причем каждый адрес должен быть выведен на отдельной строчке, оканчивающейся символом конца строки.

#include <netdb.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int c, char **v)
{
    if (c != 2)
        return -1;
    struct hostent *h;
    h = gethostbyname(v[1]);

    if (NULL == h)
    {
        printf("Error\n");
        return -1;
    }
    // printf("Canonical name %s\n", h->h_name);
    // printf("Type = %s len = %d\n", (h->h_addrtype == AF_INET) ? "ipv4" : "ipv6", h->h_length);

    int i = 0;
    while (NULL != h-> h_addr_list[i])
    {
        struct in_addr *a = (struct in_addr*) h->h_addr_list[i];
        printf("%s\n", inet_ntoa(*a));
        i++;
    }
}