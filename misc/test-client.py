import socket
import threading
import sys

def receive_server_msg():
    while True:
        print(s.recv(4096))

s = socket.socket()
s.connect((sys.argv[1], sys.argv[2]))
t = threading.Thread(target=receive_server_msg)
t.start()

while True:
    msg = input()
    s.sendall(bytes(msg, 'utf8'))

