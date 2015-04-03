import socket
th = "ya.ru"
tp = 80

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect((th,tp))
client.send("GET / HTTP/1.1\rHost: ya.ru\r\n\r\n")

response = client.recv(4096)

print response

