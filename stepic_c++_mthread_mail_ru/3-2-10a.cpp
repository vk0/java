// Еще одно задание без баллов.

// Попробуйте написать чат-сервер. Каждое сообщение, посланное одним клиентом, передается всем остальным. К началу каждого сообщения присоединяется IP-адрес клиента. Всем клиентам приходят сообщения о подключении новых участников и об отключении существующих.

// Вопросы (с кодом и без) можно оставлять в комментариях.

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>

#include <map>
#include <string>
#include <strings.h>

void err(const std::string& sErr) { std::cerr << sErr << ", errno = " << errno << std::endl; }
void messageToAll(int sockExcept, const std::string &sMsg, std::map<int, std::string> &mapClients)
{
    for (auto it = mapClients.begin(); it != mapClients.end();)
    {
        if ( it->first == sockExcept ) { ++it;   continue; }
        int nSendRes = send(it->first, sMsg.c_str(), sMsg.length(), MSG_NOSIGNAL);
        if ( nSendRes == -1 )
        {
            int nClosedSocket = it->first;
            const std::string &sClosedIp = it->second;
            shutdown(it->first, SHUT_RDWR);
            close(it->first);
            it = mapClients.erase(it);

            messageToAll(nClosedSocket, sClosedIp + " leaves.\n", mapClients);
            continue;
        }
        ++it;
    }
}


int main(int argc, char **argv)
{
    int sockMaster = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( sockMaster == -1 ) { err("Err socket()"); return -1; }
    struct sockaddr_in saMaster;
    bzero(&saMaster, sizeof(saMaster));
    saMaster.sin_family = AF_INET;
    saMaster.sin_port = htons(12345);
    saMaster.sin_addr.s_addr = INADDR_ANY;

    if ( bind(sockMaster, (struct sockaddr*)&saMaster, sizeof(saMaster)) == -1 ) { err("Err bind()"); close(sockMaster); return -1; }

    int nNoBlock = 1;
    int flags = fcntl(sockMaster, F_GETFL, 0); if ( flags == -1 ) flags = 0;
    if ( fcntl(sockMaster, F_SETFL, flags | O_NONBLOCK) == -1 ) { err("Err fcntl()"); }

    if ( listen(sockMaster, SOMAXCONN) == -1 ) { err("Err listen()"); close(sockMaster); return -1; }

    int epollInst = epoll_create1(0);
    if ( epollInst == -1 ) { err("Err epoll_create1()"); close(sockMaster); return -1; }
    struct epoll_event epollEvent;
    epollEvent.data.fd = sockMaster;
    epollEvent.events = EPOLLIN;
    if ( epoll_ctl(epollInst, EPOLL_CTL_ADD, sockMaster, &epollEvent) == -1 ) { err("Err epoll_ctl()"); close(epollInst); close(sockMaster); return -1; }

    const int MAX_EVENTS = 10;
    struct epoll_event epollEvents[MAX_EVENTS];
    char szClientIp[INET_ADDRSTRLEN];
    std::map<int, std::string> mapClients;
    char szRecvBuf[1024];
    while (1)
    {
        int nElements = epoll_wait(epollInst, epollEvents, MAX_EVENTS, -1);
        if ( nElements  == -1 ) { err("Err epoll_wait()"); close(epollInst); shutdown(sockMaster, SHUT_RDWR); close(sockMaster); return -1; }
        for (int i = 0; i < nElements; i++)
        {
            if ( epollEvents[i].data.fd == sockMaster )
            {
                struct sockaddr_in saClient;
                socklen_t nSaSize;
                int sockClient = accept(sockMaster, (struct sockaddr*)&saClient, &nSaSize);
                if ( inet_ntop(AF_INET, &(saClient.sin_addr), szClientIp, INET_ADDRSTRLEN) == NULL )
                { err("Err inet_ntop()"); close(epollInst); shutdown(sockMaster, SHUT_RDWR); close(sockMaster); return -1; }
                int nNoBlock = 1;
                int flags = fcntl(sockClient, F_GETFL, 0); if ( flags == -1 ) flags = 0;
                if ( fcntl(sockClient, F_SETFL, flags | O_NONBLOCK) == -1 ) { err("Err fcntl()"); }
                mapClients.insert(std::make_pair(sockClient, std::string(szClientIp)));
                messageToAll(sockClient, std::string("New connection ") + szClientIp + "\n", mapClients);

                epollEvent.data.fd = sockClient;
                if ( epoll_ctl(epollInst, EPOLL_CTL_ADD, sockClient, &epollEvent) == -1 ) { err("Err epoll_ctl()"); close(epollInst); shutdown(sockMaster, SHUT_RDWR); close(sockMaster); return -1; }
            }
            else
            {
                int nRecvRes = recv(epollEvents[i].data.fd, szRecvBuf, sizeof(szRecvBuf), MSG_NOSIGNAL);
                if ( nRecvRes == -1 ) { err("Err recv()"); close(epollInst); shutdown(sockMaster, SHUT_RDWR); close(sockMaster); return -1; }
                if ( nRecvRes == 0 )
                {
                    if ( errno == EAGAIN )
                        continue;
                    int sockDisc = epollEvents[i].data.fd;
                    shutdown(sockDisc, SHUT_RDWR);
                    close(sockDisc);
                    auto p = mapClients.find(sockDisc);
                    const std::string &sDiscIp = ( (p == mapClients.end()) ? "" : p->second );
                    mapClients.erase(p);
                    messageToAll(sockDisc, sDiscIp + " disconnects.\n", mapClients);
                    continue;
                }

                szRecvBuf[nRecvRes] = '\0';
                auto p = mapClients.find(epollEvents[i].data.fd);
                if ( p != mapClients.end() )
                    messageToAll(p->first, std::string("Message from ") + p->second + std::string("> ") + std::string(szRecvBuf) + "\n", mapClients);
            }
        }
    }

    for (auto p : mapClients) { shutdown(p.first, SHUT_RDWR); close(p.first); }
    close(epollInst);
    shutdown(sockMaster, SHUT_RDWR);
    close(sockMaster);
}