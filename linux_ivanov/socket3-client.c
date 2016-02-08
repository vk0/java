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
    sock = socket (PF_UNIX, SOCK_DGRAM, 0);
    if (sock == -1) {
        fprintf (stderr, "socket() error\n");
        return 1;
    }
    addr.sun_family = AF_UNIX;
    strcpy (addr.sun_path, SOCK_NAME);
    if (sendto (sock, argv[1], strlen (argv[1]), 0,
                (struct sockaddr *) &addr,
                SUN_LEN (&addr)) == -1) {
        fprintf (stderr, "sendto() error\n");
        return 1;
    }
    close (sock);
    return 0;
}