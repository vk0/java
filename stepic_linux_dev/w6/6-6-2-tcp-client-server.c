#include <stdio.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>

struct sockaddr_in local;

int server()
{
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    int cs;

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(1234);
    local.sin_family = AF_INET;

    bind(ss, (struct sockaddr*) &local, sizeof(local));
    listen(ss, 5);

    cs = accept(ss, NULL, NULL);

    char buf[BUFSIZ];
    read(cs, buf, BUFSIZ);
    printf("%s\n", buf);
    close(cs);
}

int client()
{
    int s = socket(AF_INET, SOCK_DGRAM, 0);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(1234);
    local.sin_family = AF_INET;

    connect(s, (struct sockaddr*) &local, sizeof(local));

    char buf[BUFSIZ] = "Hello\n";
    write(s, buf, strlen(buf) + 1);
    close(s);

}

int main(int c, char **v)
{
    if (c!=2)
    {
        return printf("Use: %s [s|c]\n", v[0]);
    }
    // struct sockaddr_in local;

    if (v[1][0] == "s")
    {
        server();
    }
    if (v[1][0] == "c")
    {
        client();
    }
}