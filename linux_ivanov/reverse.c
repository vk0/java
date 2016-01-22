#include <unistd.h>
#define BUF_SIZE 4096

char buffer [BUF_SIZE];

int main (void)
{
int i;
for (i = 0; (read (0, &buffer[i], 1) > 0) ||
    (i < BUF_SIZE); i++) {
if (buffer[i] == '\n') {
    i--;
    break;
    }
}
for (; i >= 0; i--) write (1, &buffer[i], 1);
    write (1, "\n", 1);
    return 0;
}