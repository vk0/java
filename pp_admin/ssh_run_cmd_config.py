#!/usr/bin/env python
import subprocess
import ConfigParser

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

ips, cmds = readConfig()

for ip in ips:
    for cmd in cmds:
        subprocess.call('ssh root@%s %s' % (ip, cmd), shell=True)