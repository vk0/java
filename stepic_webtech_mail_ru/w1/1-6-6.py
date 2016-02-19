# Разработать простейший TCP echo сервер.

# Требования

#     Запускается на порту 2222
#     Получает сообщения длинной не более 1024 байт и отправляет обратно клиенту
#     Закрывает соединение при получении сообщения с текстом close﻿

import socket

#empty host string. bind() will use the current machine address
host = '0.0.0.0'
port = 2222
backlog = 5
size = 1024

#create a socket
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#restart server quickly when it terminates. also to reuse the same port
serverSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

#bind the socket to a port
serverSocket.bind((host, port))

#listen for connections
serverSocket.listen(backlog)

# print "server running on ", serverSocket.getsockname()
# print "waiting for connections "

try:
    while 1:
        clientSocket, address = serverSocket.accept()
        # print "connected from ", address

        while 1:
            receivedData = clientSocket.recv(size)
            if receivedData == "close\n" or receivedData == "close" or not receivedData:
                break

            clientSocket.send(receivedData)
        clientSocket.close()
        # print "disconnected from ", address
finally:
    serverSocket.close()
