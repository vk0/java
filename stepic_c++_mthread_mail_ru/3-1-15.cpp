// Тут раньше была простая задача на 10 баллов. Но я решил перенести эти баллы в тест, а тут дать другую задачу, не оцениваемую.

// Напишите эхо-сервер (IPv4, TCP). Это сервер, который возвращает то, что ему прислано. Вопросы (с кодом и без) можно задавать в комментариях.

// Тестировать сервер можно с помощью утилит telnet и nc - выбирайте по вкусу.

//c++ -o echo_server_c++ 3-1-15.cpp

#include <iostream>
#include <sys/types.h>          /* man 2 socket */
#include <sys/socket.h>
#include <netinet/in.h>         /* man 2 bind   */
#include <unistd.h>             /* man 2 close  */
#include <sys/ioctl.h>          /* FIOBIO */

int main() {
    int master_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    sockaddr_in sa;
    sa.sin_family     = AF_INET;
    sa.sin_port       = htons(6666);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(master_socket, (sockaddr*)&sa, sizeof(sa)))
        std::cout << "Err in bind\n";
    else if (listen(master_socket, SOMAXCONN))
        std::cout << "Err in listen\n";
    else {
        int optval = 1;
        setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

        while (1) {
            int slave_socket = accept(master_socket, 0, 0);
            int buffer[5] = {0, 0, 0, 0, 0};

            unsigned int buf_size = 5;
            int res = 1;
            while (res > 0) {
                res = recv(slave_socket, buffer, buf_size, MSG_NOSIGNAL);
                if (res > 0) {
                    send(slave_socket, buffer, res, MSG_NOSIGNAL);
                }
            }
            shutdown(slave_socket, SHUT_RDWR);
            close(slave_socket);
        }
        return 0;
    }
}