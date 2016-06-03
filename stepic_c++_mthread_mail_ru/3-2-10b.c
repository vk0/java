// Еще одно задание без баллов.

// Попробуйте написать чат-сервер. Каждое сообщение, посланное одним клиентом, передается всем остальным. К началу каждого сообщения присоединяется IP-адрес клиента. Всем клиентам приходят сообщения о подключении новых участников и об отключении существующих.

// Вопросы (с кодом и без) можно оставлять в комментариях.

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_EVENTS 32


int set_nonblock(int fd) {
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
// Convert ip address from sockaddr to const char*. This function allocate memory for string at given pointer s
const char* get_ip_addr(struct sockaddr * restrict in_addr, char * s) {
    switch (in_addr->sa_family) {
    case AF_INET: {
        struct sockaddr_in *addr_in = (struct sockaddr_in *)in_addr;
        s = malloc(INET_ADDRSTRLEN);
        s = inet_ntop(AF_INET, &(addr_in->sin_addr), s, INET_ADDRSTRLEN);
        break;
    }
    case AF_INET6: {
        struct sockaddr_in6 *addr_in6 = (struct sockaddr_in6 *)in_addr;
        s = malloc(INET6_ADDRSTRLEN);
        s = inet_ntop(AF_INET6, &(addr_in6->sin6_addr), s, INET6_ADDRSTRLEN);
        break;
    }
    default:
        break;
    }
    if (s == 0) printf("ERROR get_ip_addr: %d\n", errno);
    return s;
}

//struct for store connected sockets data in the linked list
struct node {
    // socket descriptor
    int fd;
    // ip address
    char *ip;
    struct node *next;
    struct node *prev;
};

// Append new node to the collection root. If root == 0 create new collection
struct node* add_node(struct node* root, int fd, char *ip) {
    if (root == 0) {
        root = (struct node *) malloc(sizeof(struct node));
        root->next = 0;
        root->prev = 0;
        root->fd = fd;
        root->ip = ip;
        return root;
    } else {
        struct node *next = 0;
        next = root;
        while (next->next != 0)
        {
            next = next->next;
        }
        next->next = malloc(sizeof(struct node));
        struct node *prev = next;
        next = next->next;
        next->fd = fd;
        next->ip = ip;
        next->next = 0;
        next->prev = prev;
        return next;
    }
}

// Delete node root from collection, and if needed change head or (and) tail pointers
struct node* del_node(struct node* root, int fd, struct node** head, struct node** tail) {
    if (root == 0) {
        return root;
    } else {
        struct node *next = 0;
        next = root;
        while (next != 0)
        {
            if (next->fd == fd) {
                struct node* prev = next->prev;
                if (next == *head) {
                    (*head) = next->next;
                    (*head)->prev = 0;
                }
                if (next == *tail) {
                    (*tail) = next->prev;
                    (*tail)->next = 0;
                } else {
                    next->next->prev = prev;
                    prev->next = next->next;
                }
                free(next->ip);
                free(next);
                break;
            }
            next = next->next;
        }
        return *head;
    }
}

// Find node in the collection root by socket descriptor fd
struct node* find_node(struct node* root, int fd) {
    if (root == 0) {
        return root;
    } else {
        struct node *next = 0;
        next = root;
        while (next != 0)
        {
            if (next->fd == fd) {
                return next;
            }
            next = next->next;
        }
        return 0;
    }
}

// Send message to all sockets in the collection root, exclude current socket
void send_message_to_all_clients(char *message, struct node* root, struct node* current) {
    char *message_str = 0;
    asprintf(&message_str, message, current->ip);
    int message_len = strlen(message_str);
    struct node* next = root;
    while (next != 0) {
        if (next->fd == current->fd) {
            next = next->next;
            continue;
        }
        send(next->fd, message_str, message_len, MSG_NOSIGNAL);
        next = next->next;
    }
    free(message_str);
}

int main(int argc, char **argv)
{
    int master_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(12345);
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(master_socket, (struct sockaddr*)(&sock_addr), sizeof(sock_addr));

    set_nonblock(master_socket);

    listen(master_socket, SOMAXCONN);

    int EPoll = epoll_create1(0);
    struct epoll_event Event;
    Event.data.fd = master_socket;
    Event.events = EPOLLIN;

    epoll_ctl(EPoll, EPOLL_CTL_ADD, master_socket, &Event);

    // linked list for store connected sockets data
    struct node* head = add_node(0, master_socket, 0);
    struct node* tail = head;

    while (1) {
        struct epoll_event Events[MAX_EVENTS];
        int N = epoll_wait(EPoll, Events, MAX_EVENTS, -1);
        if (N < 0) {
            switch (errno) {
            case EBADF:  printf("epfd is not a valid file descriptor.\n"); break;
            case EFAULT: printf("The memory area pointed to by events is not accessible.\n"); break;
            case EINTR:  printf("The call was interrupted by a signal handler.\n"); break;
            case EINVAL: printf("epfd is not an epoll file descriptor.\n"); break;
            };
            continue;
        };
        for (int i = 0; i < N; ++i) {
            if (Events[i].data.fd == master_socket) {

                struct sockaddr in_addr;
                socklen_t in_len = sizeof(in_addr);
                int slave_socket = accept(master_socket, &in_addr, &in_len);
                const char *client_ip = NULL;
                client_ip = get_ip_addr(&in_addr, client_ip);

                set_nonblock(slave_socket);

                tail = add_node(tail, slave_socket, client_ip);
                // Send to all other clients info: Client [ip] connected.
                char message_str[] = "Client [%s] connected.\n\0";
                send_message_to_all_clients(message_str, head, tail);

                struct epoll_event Event;
                Event.data.fd = slave_socket;
                Event.events = EPOLLIN;
                epoll_ctl(EPoll, EPOLL_CTL_ADD, slave_socket, &Event);
            } else {
                static char buffer[1025];
                int recv_res = recv(Events[i].data.fd, buffer, 1024, MSG_NOSIGNAL);
                if ((recv_res == 0) && (errno != EAGAIN)) {
                    // Send to all other clients info: Client [ip] disconnected.
                    char message_str[] = "Client [%s] disconnected.\n\0";
                    struct node *cur_client = find_node(head, Events[i].data.fd);
                    send_message_to_all_clients(message_str, head, cur_client);
                    // Delete and close current slave_socket
                    del_node(cur_client, Events[i].data.fd, &head, &tail);
                    shutdown(Events[i].data.fd, SHUT_RDWR);
                    close(Events[i].data.fd);
                }
                else if (recv_res > 0) {
                    // Send to all other clients recived message: [ip>]: message
                    char *message_str = 0;
                    struct node *cur_client = find_node(head, Events[i].data.fd);
                    buffer[recv_res] = 0;
                    char mask[] = "%s\0";
                    asprintf(&message_str, "[%s]> %s", mask, buffer);
                    send_message_to_all_clients(message_str, head, cur_client);
                }
            }
        }
    }
    return 0;
}