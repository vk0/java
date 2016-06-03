// Еще одно задание без баллов.

// Попробуйте написать чат-сервер. Каждое сообщение, посланное одним клиентом, передается всем остальным. К началу каждого сообщения присоединяется IP-адрес клиента. Всем клиентам приходят сообщения о подключении новых участников и об отключении существующих.

// Вопросы (с кодом и без) можно оставлять в комментариях.

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_EVENTS 32

// functions
int set_nonblock(int fd);
std::string sockPeerToStr (const int sockFd);
void informAllAboutGuest (const std::set<int> & SlaveSockets,
                          const int & slaveSocket,
                          const bool & newOne);


int main(int argc, char **argv)
{
    int MasterSocket = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int on = 1;
    int status = setsockopt ( MasterSocket,
                              SOL_SOCKET,
                              SO_REUSEADDR,
                              (const char *) &on, sizeof(on));
    std::set<int> SlaveSockets;

    struct sockaddr_in SockAddr;
    SockAddr.sin_family = AF_INET;
    const int PORT_12345 = 12345;
    SockAddr.sin_port = htons(PORT_12345);
    SockAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(MasterSocket, (struct sockaddr *) (&SockAddr), sizeof(SockAddr));

    // make MasterSocket non-blocking
    set_nonblock(MasterSocket);

    listen(MasterSocket, SOMAXCONN);

    int EPoll = epoll_create1(0);
    struct epoll_event Event;
    Event.data.fd = MasterSocket;
    Event.events = EPOLLIN;
    epoll_ctl (EPoll, EPOLL_CTL_ADD, MasterSocket, &Event);

    while (true) {
        struct epoll_event Events[MAX_EVENTS];
        int N = epoll_wait(EPoll, Events, MAX_EVENTS, -1);

        for (int i = 0; i < N; ++ i) {
            if (Events[i].data.fd == MasterSocket) {
                int SlaveSocket = accept(MasterSocket, 0, 0);
                set_nonblock(SlaveSocket);

                // create and register epoll object
                struct epoll_event Event;
                Event.data.fd = SlaveSocket;
                Event.events = EPOLLIN;
                epoll_ctl(EPoll, EPOLL_CTL_ADD, SlaveSocket, & Event);
                SlaveSockets.insert(SlaveSocket);

                // inform all chat server's clients about new guest
                informAllAboutGuest(SlaveSockets, SlaveSocket, true);
            }
            else {
                const unsigned int BUF_SIZE = 1024;
                char Buffer [BUF_SIZE];
                int recvResult = recv(Events[i].data.fd, Buffer, BUF_SIZE, MSG_NOSIGNAL);
                if ((recvResult == 0) && (errno != EAGAIN)) {
                    // inform all chat server clients about old guest
                    int SlaveSocket = Events[i].data.fd;
                    informAllAboutGuest(SlaveSockets, SlaveSocket, false);
                    // shutdown and close connection
                    shutdown(Events[i].data.fd, SHUT_RDWR);
                    close(Events[i].data.fd);
                    // erase socket from set
                    SlaveSockets.erase(Events[i].data.fd);
                }
                else if (recvResult > 0) {
                    std::string msg = sockPeerToStr(Events[i].data.fd);
                    msg += ": ";
                    msg += Buffer;
                    // resend incoming message to all
                    for (auto iter = SlaveSockets.begin(); iter != SlaveSockets.end(); ++ iter) {
                        send(*iter, msg.c_str(), msg.size(), MSG_NOSIGNAL);
                    }
                    // print incoming message on console
                    std::cout << msg; //<<std::endl;
                }
            }
        }
    }

    return 0;
}

int set_nonblock(int fd)
{
    int flags;
#if defined(O_NONBLOCK)
    if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
        flags = 0;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
#else
    flags = 1;
    return ioctl(fd, FIOBIO, &flags);
#endif
}

std::string sockPeerToStr (const int sockFd) {

    socklen_t len;
    struct sockaddr_storage addr;
    char ipstr[INET6_ADDRSTRLEN];
    int port;

    len = sizeof addr;
    getpeername(sockFd, (struct sockaddr*)&addr, &len);

    // deal with both IPv4 and IPv6:
    if (addr.ss_family == AF_INET) {
        // IP v4
        struct sockaddr_in *s = (struct sockaddr_in *)&addr;
        port = ntohs(s->sin_port);
        inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
    } else {
        // IP v6
        struct sockaddr_in6 *s = (struct sockaddr_in6 *)&addr;
        port = ntohs(s->sin6_port);
        inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
    }

    std::string res = ipstr;
    res += ":";
    res += std::to_string(port);
    return res;
}

void informAllAboutGuest (const std::set<int> & SlaveSockets,
                     const int & slaveSocket,
                     const bool & newOne)
{
    std::string strHostPort;
    for (auto iter = SlaveSockets.begin(); iter != SlaveSockets.end(); ++ iter) {
        if (newOne) {
            strHostPort += "new client: " + sockPeerToStr(slaveSocket);
        }
        else {
            strHostPort += "disconnected client: " + sockPeerToStr(slaveSocket);
        }
        // send message to all sockets
        send(*iter, strHostPort.c_str(), strHostPort.size() + 1, MSG_NOSIGNAL);
    }
    std::cout << strHostPort << std::endl;
}