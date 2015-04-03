#!/usr/bin/env python2

import subprocess
import ConfigParser
from threading import  Thread
from Queue import Queue
import time

start = time.time()
queue = Queue()

def readConfig(file='config.ini'):
    ips = []
    cmds = []
    Config = ConfigParser.ConfigParser()
    Config.read(file)
    machines = Config.items('MACHINES')
    commands = Config.items('COMMANDS')
    for ip in machines:
        ips.append(ip[1])
    for cmd in commands:
        cmds.append(cmd[1])
    return  ips, cmds

def launcher(i,q,cmd):
    while True:
        ip = q.get()
        print('Tread %s: Running %s to %s' % (i,cmd,ip))
        subprocess.call('ssh root@%s %s' % (ip, cmd), shell=True)
        q.task_done()

ips, cmds = readConfig()

if len(ips) < 25:
    num_threads = len(ips)
else:
    num_threads = 25

for i in range(num_threads):
    for cmd in cmds:
        worker = Thread(target=launcher, args=(1, queue, cmd))
        worker.setDaemon(True)
        worker.start()
print('Main Tread Waiting')
for ip in ips:
    queue.put(ip)
queue.join()
end = time.time()
print('Work Completed in %s seconds' % end)