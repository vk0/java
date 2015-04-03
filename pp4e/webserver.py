import os,sys
from http.server import HTTPServer, CGIHTTPRequestHandler

webdir = '.'
port = 80

os.chdir(webdir)
srvraddr=("",port)
srvobj = HTTPServer(srvraddr, CGIHTTPRequestHandler)
srvobj.serve_forever()
