#!/usr/bin/env python2

import subprocess

uname = "uname"
uname_arg = "-a"
print "Sysinfo with %s command:\n" % uname
subprocess.call([uname, uname_arg])
