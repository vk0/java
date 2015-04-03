import re
import subprocess

ARP = 'arp'
IP = '10.0.0.1'
CMD = '%s %s' % (ARP, IP)
macPattern = re.compile(':')

def getMac():
    p = subprocess.Popen(CMD, shell=True, stdout=subprocess.PIPE)
    out = p.stdout.read()
    results = out.split()
    for chunk in results:
        if re.search(macPattern, chunk):
            return chunk

if __name__ == '__main__':
    macAddr = getMac()
    print(macAddr)
