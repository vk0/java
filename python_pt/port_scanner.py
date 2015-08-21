for port in range(1000,1001):
    print "[+] The port is: "+str(port)


import socket
s = socket.socket()
# try:
#     s.connect(('192.168.56.101', 22))
#     banner = s.recv(1024)
#     print banner
# except:pass

# for port in range(20,25):
#     try:
#         print "[+] Attempting to connect to 192.168.56.101:"+str(port)
#         s.connect(('192.168.56.101', port))
#         banner = s.recv(1024)
#         if banner:
#             print "[+] Port "+str(port)+" open: "+banner
#         s.close()
#     except: pass

hosts = ['127.0.0.1', '192.168.56.101', '10.0.0.1']
ports = [22, 445, 80, 443, 3389]
for host in hosts:
    for port in ports:
        try:
            print "[+] Connecting to "+host+":"+str(port)
            s.connect((host, port))
            banner = s.recv(1024)
            if banner:
                print "[+] Port "+str(port)+" open: "+banner
            s.close()
        except:pass