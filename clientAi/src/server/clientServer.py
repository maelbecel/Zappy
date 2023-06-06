##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## clientServer
##

import socket
from ..exception.clientException import clientException as cEx


class clientServer:
    def __init__(self, port, host):
        print("Init clientServer")
        self.port = port  # port
        self.host = host  # ip
        self.socket = None

    def connect(self):
        # AF_INET = IPv4 / SOCK_STREAM = TCP
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        if self.socket is None:
            cEx("Error: socket is null")
        if self.socket.connect((self.host, int(self.port))) == -1:
            cEx("Error: socket is not connect")
        print("Connect to server")

    def disconnect(self):
        self.socket.close()
        if self.socket is not None:
            cEx("Error: socket is not close")
        print("Disconnect to server")

    def send(self, message):
        if self.socket is None:
            cEx("Error: socket is null")
        print("Send message to server: " + message + "\n")
        self.socket.sendall(message.encode("ascii"))

    def receive(self):
        if self.socket is None:
            cEx("Error: socket is null")
        response = self.socket.recv(1024).decode()
        if response is None:
            print("Error: response is null")
        # print("Receive message from server: " + response + "\n")
        return response

    def getSocket(self):
        return self.socket

    def getPort(self):
        return self.port

    def getHost(self):
        return self.host
