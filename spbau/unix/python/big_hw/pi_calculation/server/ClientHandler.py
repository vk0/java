import pickle
import threading
__author__ = 'luckyman'


class ClientThread(threading.Thread):
    _clientPool = None
    _resultHolder = None
    _stop = False
    def __init__(self, clientPool, resultHolder):
        threading.Thread.__init__(self)
        self._clientPool = clientPool
        self._resultHolder = resultHolder

    def run(self):
        while not self._stop:
            if self._clientPool is not None:
                client = self._clientPool.get()
                if client is not None:
                    print 'Received connection:', client[1][0]
                    client[0].send("STATUS")
                    status = client[0].recv(7)
                    if status == "GET_NEW":
                        portion = self._resultHolder.getNextPortion()
                        dumps = pickle.dumps(portion)
                        client[0].send(dumps)
                        print "send new block:" + str(portion)
                    elif status == "REC_RES":  #RECORD RESULT
                        print "receive new result"
                        read = client[0].recv(4096)
                        if read is not None:
                            self._resultHolder.addCalculatedPart(read)
                    client[0].close()
                    print 'Closed connection:', client[1][0]

    def stop(self):
        self._stop = True
