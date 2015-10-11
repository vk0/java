import os
import time
from Config import serverPort, serverAddress,numOfThreads
from Pi import calculatePI

__author__ = 'luckyman'

import pickle
import socket
import threading

class ConnectionThread(threading.Thread):
    def run(self):
        while True:
            cpuLoadStatus = self.getCPULoadStatus()
            if cpuLoadStatus < 50 and threading.activeCount() < numOfThreads:
                print cpuLoadStatus
                calcThread = CalculateThread()
                calcThread.start()
            else:
                time.sleep(1)

    def getCPULoadStatus(self):
        p=os.popen( 'vmstat' )
        r=p.readlines()
        p.close()

        res = r[2].split()
        idle_proc = int(res[14])
        return 100 - idle_proc

class CalculateThread(threading.Thread):

    def run(self):
        client = socket.socket()
        connect = False
        try:
            client.connect ((serverAddress, serverPort))
            connect = True
        except BaseException:
            connect = False

        if connect:
            print client.recv(7)
            client.send("GET_NEW")
            config = pickle.loads(client.recv(4096))
            client.close()
            connect = False

            result = calculatePI(config["startN"], config["stopN"], config["prec"])
            client = socket.socket()
            try:
                client.connect((serverAddress, serverPort))
                connect = True
            except BaseException:
                connect = False

            if connect:
                print client.recv(7)
                client.send("REC_RES")
                client.send(str(result))
                client.close()
            else:
                print "can't send result"

thread = ConnectionThread()
thread.start()
