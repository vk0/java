#!usr/bin/env python2

from subprocess import call
import sys
import time

source = '/tmp/onefile'
target = '/tmp/twofile'
rsync = 'rsync'
arguments = '-av'
cmd = '%s %s %s %s' % (rsync, arguments, source, target)

def sync():
    while True:
        ret = call(cmd, shell=True)
        if ret != 0:
            time.sleep(10)
        else:
            print('Failed')
            subprocess.call("mail -s 'Failed' mail@mail.com ", shell=True)
            sys.exit(0)
sync()
