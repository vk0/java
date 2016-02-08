#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <sys/un.h>
#include <stdlib.h>
#define QUEUE_LENGTH 10
#define BUF_LEN 256
#define SOCK_NAME "mysocket"
int main (void)
{
    int sock;
    struct sockaddr_un saddr;
    char * buf;
    int count;
    sock = socket (PF_UNIX, SOCK_DGRAM, 0);
    if (sock == -1) {
        fprintf (stderr, "socket() error\n");
        return 1;
    }
    buf = (char *) malloc (BUF_LEN);
    if (buf == NULL) {
        fprintf (stderr, "malloc() error\n");
        return 1;
    }
    saddr.sun_family = AF_UNIX;
    strcpy (saddr.sun_path, SOCK_NAME);
    if (bind (sock, (struct sockaddr *) &saddr,
              SUN_LEN (&saddr)) == -1) {
        fprintf (stderr, "bind() error\n");
        return 1;
    }
    while (1) {
        if ((count = recvfrom (sock, buf, BUF_LEN - 1,
                               0, NULL, NULL)) == -1)
        {
            fprintf (stderr, "recvfrom() error\n");
            return 1;
        }
        buf[count] = '\0';
        printf (">> %s\n", buf);
        if (!strcmp (buf, "exit")) break;
    }
    free (buf);
    close (sock);
    unlink (SOCK_NAME);
    return 0;
}