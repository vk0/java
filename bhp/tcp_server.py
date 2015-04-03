import socket
import threading

bip = "0.0.0.0"
bp = 9998

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((bip,bp))
server.listen(5)

print "[*] Listening in %s:%d" % (bip, bp)

def handle_client(client_socket):
    req = client_socket.recv(1024)
    print "[*] Received: %s" % req
    client_socket.send("ACK!")
    client_socket.close()

while True:
    client, addr = server.accept()
    print "[*] Accepted connection from: %s:%d" % (addr[0], addr[1])
    client_handler = threading.Thread(target=handle_client,args=(client,))
    client_handler.start()