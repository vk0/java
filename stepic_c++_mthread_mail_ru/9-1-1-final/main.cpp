#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <string>

#include <thread>
#include <stdlib.h>

#ifdef WIN32
#include <winsock2.h>
#define errNum WSAGetLastError
typedef  ssize_t socklen_t;
#define ioctl  ioctlsocket
#endif

#ifdef UNIX
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <errno.h>
#include <arpa/inet.h>
#include <stdexcept>
#include <sys/ioctl.h>
#include <sys/stat.h>
#define INVALID_SOCKET -1
#define SOCKET_ERROR   -1
int errNum () { return errno;}
#define closesocket close
#endif

#include <mutex>
#include <cstdio>
#include <stdarg.h>
#include <string.h>

template <typename Error>
void Throw(const char* format, ...) {

    va_list ap;
    char buff[256];
    va_start(ap, format);
    vsnprintf(buff, 256, format, ap);
    va_end(ap);

    throw Error (buff);
}
#define ThrowRuntime Throw<std::runtime_error>

FILE* logFile = nullptr;
std::mutex logMutex;
void log (const char* format, ...) {
    if (logFile == nullptr)
        return;

    std::lock_guard<std::mutex> lock(logMutex);

    va_list ap;
    va_start(ap, format);
    vfprintf(logFile, format, ap);
    va_end(ap);

    fflush(logFile);
}
//-----------------------------------------------------------------------------
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}
//------------------------------------------------------------------------------

int demonize () {
    int pid = fork();

    switch (pid) {
    case 0:
        umask(0);
        setsid();
        //chdir("/");//?

        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        break;

    case -1:
        exit(EXIT_FAILURE);
        break;

    default:
        exit(EXIT_SUCCESS);
        break;
    }

    return 0;
}

int openSocket(const std::string &host, unsigned int port ) {

    //Create a socket
    int serverSocket = INVALID_SOCKET;
    if ((serverSocket = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
        ThrowRuntime ( "Could not create socket : %d" , errNum() );

    log("Socket created.\n");

    //Prepare the sockaddr_in structure
    sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons( port );

    unsigned char buf[sizeof(struct in6_addr)];
    inet_pton(AF_INET, host.c_str(), buf);
    server.sin_addr.s_addr = *((uint32_t*)buf);
    //server.sin_addr.s_addr = INADDR_ANY;

    //Bind
    if ( bind(serverSocket , (struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
        ThrowRuntime("Bind failed with error code : %d" , errNum());
    log("Bind done.\n");

    if ( 0 != listen(serverSocket, 50))
        ThrowRuntime("Listen failed with error code : %d", errNum());
    log("Server socket done.\n");

    return serverSocket;
}

//------------------------------------------------------------------------------
void processHttpReq (const std::string &req, int socket) {
    auto lines = split (req, '\x0A');
    auto header = split (lines[0], ' ');

    if ( strcasecmp (header[0].c_str(), "GET") == 0) {
        log("GET req\n");
        auto resName = header[1];

        //if (resName == "/")
        //    resName = "/index.html";

        if (resName[0] == '/')
            resName = std::string(&resName[1]);
        resName = resName.substr(0, resName.find('?', 0));

        auto f = fopen(resName.c_str(), "rb");
        if (f) {
            fseek(f, 0, SEEK_END);
            auto size = ftell(f);
            fseek(f, 0, SEEK_SET);

            std::vector<char> buff;
            buff.resize(size);
            fread(buff.data(), size, 1, f);
            fclose(f);

            std::string header = std::string("HTTP/1.0 200 OK\x0D\x0A") +
                                 "Content-Type: text/html\x0D\x0A" +
                                 "Content-Length: " + std::to_string(buff.size()) + "\x0D\x0A" +
                                 "\x0D\x0A";
            write(socket, header.c_str(), header.size());

            write(socket, buff.data(), buff.size());

            log("Resource %s is sent.\n", resName.c_str());
        }
        else {
            log("Resource %s is not found.\n", resName.c_str());
            char respound[] = "HTTP/1.0 404 NOT FOUND\x0D\x0A"
                              "Content-Length: 0\x0D\x0A"
                              "Content-Type: text/html\x0D\x0A\x0D\x0A";
            write(socket, respound, sizeof(respound));
        }
    }
    else
        log("Unsuported req\n");

}

void processConection (int socket) {

    auto threadId = std::this_thread::get_id();
    unsigned int conectionId = ((unsigned int*)&threadId)[0];
    log("Open connection %i\n", conectionId);

    char buffer[10 * 1024];
    memset(buffer, 0, sizeof(buffer));

    while (true) {
        auto size = read (socket, &buffer, 10 * 1024);
        if (size <= 0)
            break;

        log("New reqwest in connection %i \n%s\n\n", conectionId, buffer);

        processHttpReq (buffer, socket);
        break;//ToDo add Keep-Alive

    }

    close (socket);
    log("Close connection %i\n", conectionId);
}

int main(int argc, char *argv[])
{
    std::string ip;
    std::string port;
    std::string dir;

    int  opt;
    while ((opt = getopt(argc, argv, "h:p:d:")) != -1) {
        switch (opt) {
        case 'h':
            ip = optarg;
            break;
        case 'p':
            port = optarg;
            break;
        case 'd':
            dir = optarg;
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    demonize ();

    logFile = fopen ("/tmp/stepic_final_log.txt", "wb");
    if (logFile == NULL) {
        //printf("Can't create log");
        //exit(EXIT_FAILURE);
    }

    if (ip == "" or port == "" or dir == "") {
        log("You can't set ip, port or dir");
        exit(EXIT_FAILURE);
    }

    log("Start server %s : %s in %s \n\n", ip.c_str(), port.c_str(), dir.c_str());

    chdir(dir.c_str());

    auto serverSocket = openSocket(ip, std::stoi(port));
    while (1) {

        int newsock = INVALID_SOCKET;
        sockaddr_in  cli_addr;
        socklen_t cli_len;
        if (INVALID_SOCKET == (newsock = accept(serverSocket, (struct sockaddr *) &cli_addr, &cli_len)) )
            ThrowRuntime("accept() failed: %d\n", errno);

        std::thread thread (processConection, newsock);
        thread.detach();
    }

    closesocket(serverSocket);
    fclose(logFile);

    exit(EXIT_SUCCESS);
}
