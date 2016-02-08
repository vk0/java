// Создайте очередь сообщения POSIX с именем:

// /test.mq

// Тестовая среда пошлет в нее сообщение.

// Получите его и сохраните в /home/box/message.txt

//touch /home/box/message.txt
//./msgq_posix

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 1000;
    attr.mq_curmsgs = 0;
    mqd_t mq = mq_open("/test.mq", O_CREAT | O_RDONLY, 0777, &attr);
    char buffer[1000];
    unsigned int r = mq_receive(mq, buffer, 1000, 0);
    int f = open("/home/box/message.txt", O_RDWR);
    write(f, buffer, r);
    close(f);
}