from MainThread import MainThread
import sys

__author__ = 'luckyman'

mainThread = MainThread()
mainThread.start()
while True:
    command = sys.stdin.readline()
    if command is not None:
        command = command.strip()
        if command == "pi":
            print mainThread._resultHolder.readResult()
        elif command == "client":
            mainThread.printClients()
        elif command == "exit":
            mainThread.stop()
            break
  