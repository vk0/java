#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#define BUF_LEN 4096
#define HTTP_PORT 80

int main (int argc, char ** argv)
{
    int sock, count;
    char * buf;
    struct hostent * host;
    struct sockaddr_in addr;
    if (argc < 2) {
        fprintf (stderr, "Too few arguments\n");
        return 1;
    }
    buf = (char *) malloc (BUF_LEN);
    if (buf == NULL) {
        fprintf (stderr, "malloc() error\n");
        return 1;
    }
    sock = socket (PF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf (stderr, "socket() error\n");
        return 1;
    }
    addr.sin_family = AF_INET;
    host = gethostbyname (argv[1]);
    if (host == NULL) {
        fprintf (stderr, "Unknown server\n");
        return 1;
    }
    addr.sin_addr = * (struct in_addr*)
                    host->h_addr_list[0];
    addr.sin_port = htons (HTTP_PORT);
    if (connect (sock, (struct sockaddr*) &addr,
                 sizeof (addr)) == -1) {
        fprintf (stderr, "connect() error\n");
        return 1;
    }
    strcpy (buf, "GET /\n");
    write (sock, buf, strlen (buf));
    while ((count = read (sock, buf, BUF_LEN)) > 0)
        write (1, buf, count);
    close (sock);
    free (buf);
    return 0;
}