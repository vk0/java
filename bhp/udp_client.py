import socket
th = "127.0.0.1"
tp = 9998

client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

client.sendto("ABCD", (th,tp))
data, addr = client.recvfrom(4096)
print data
