#include <stdio.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <string.h>
#define SOCK_NAME "mysocket"
int main (int argc, char ** argv)
{
    int sock;
    struct sockaddr_un addr;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    sock = socket (PF_UNIX, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf (stderr, "socket() error\n");
        return 1;
    }
    addr.sun_family = AF_UNIX;
    strcpy (addr.sun_path, SOCK_NAME);
    if (connect (sock, (struct sockaddr *) &addr,
                 SUN_LEN (&addr)) == -1) {
        fprintf (stderr, "connect() error\n");
        return 1;
    }
    if (write (sock, argv[1], strlen (argv[1])) == -1) {
        fprintf (stderr, "write() error\n");
        return 1;
    }
    close (sock);
    return 0;
}

// $ gcc -o socket2-server socket2-server.c
// $ ./socket2-server
// Откроем теперь другое терминальное окно и начнем передавать серверу запросы:
// $ gcc -o socket2-client socket2-client.c
// $ ./socket2-client Hello
// $ ./socket2-client World
// $ ./socket2-client Linux