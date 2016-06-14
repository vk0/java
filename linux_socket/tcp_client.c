#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(void)
{
    int s;
    char buf[256] = "Привет! Hello!\n";
    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons((u_short) 1234);

    s = socket(PF_INET, SOCK_STREAM, 0);
    connect(s, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    send(s, buf, strlen(buf), 0);
    close(s);
}