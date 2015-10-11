from Queue import Queue
import socket
import threading
from Config import *
from ClientHandler import ClientThread
from ResultHolder import ResultHolder

__author__ = 'luckyman'

class MainThread(threading.Thread):
    _threads = []
    _resultHolder = ResultHolder()
    _stop = False

    def run(self):
        server = socket.socket()

        server.bind((serverAddress, serverPort))
        server.listen(0)
        clientPool = Queue()

        for i in xrange(numOfThreads):
            self._threads.append(ClientThread(clientPool, self._resultHolder))

        for thread in self._threads:
            thread.start()

        while not self._stop:
            clientPool.put(server.accept())

        for thread in self._threads:
            thread.stop()

    def printClients(self):
        pass

    def stop(self):
        self._stop = True

  