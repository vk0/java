# Измените ваш echo сервер так, что бы он работать одновременно с 10 клиентами.

# Протокол передачи такой же как в прошлой задаче.

import asyncore, socket

class Server(asyncore.dispatcher):
    def __init__(self, host, port):
        asyncore.dispatcher.__init__(self)
        self.create_socket(socket.AF_INET, socket.SOCK_STREAM)
        self.bind(('', port))
        self.listen(1)

    def handle_accept(self):
        # when we get a client connection start a dispatcher for that
        # client
        socket, address = self.accept()
        print 'Connection by', address
        EchoHandler(socket)

class EchoHandler(asyncore.dispatcher_with_send):
    # dispatcher_with_send extends the basic dispatcher to have an output
    # buffer that it writes whenever there's content
    def handle_read(self):
        self.out_buffer = self.recv(1024)
        if not self.out_buffer or self.out_buffer == "close" or self.out_buffer == "close\n":
            self.close()

s = Server('', 2222)
asyncore.loop()