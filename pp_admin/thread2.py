import subprocess
import time

IP_LIST = ['google.com','yandex.ru']

cmd_stub = 'ping -c 5 %s'

def do_ping(addr):
    print(time.asctime(), "Doing ping for", addr)
    cmd = cmd_stub % (addr,)
    return subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE)

z = []
for ip in IP_LIST:
    p = do_ping(ip)
    z.append((p, ip))
for p, ip in z:
    print(time.asctime(), "Waiting for", ip)
    p.wait()
    print(time.asctime(), ip, "Returned", p.returncode)
