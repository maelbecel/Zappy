##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## clientAi
##

from action.clientAction import enumActions as cAct

import exception.clientException as cEx
import server.clientServer as cServ


class clientAi:
    def __init__(self, teamName, port, host):
        print("Init clientAi")
        self.alive = True
        self.mapSize = [0, 0]
        self.response = None
        self.availablePlace = 0
        self.teamName = teamName + "\n"
        self.client = cServ.clientServer(port, host)

    def getConnectionResponse(self):
        self.availablePlace = int(self.response[0])
        self.response = self.response[1].split(" ")
        if len(self.response) != 2:
            raise cEx.clientException("Error: map size is invalid")
        self.mapSize[0] = int(self.response[0])
        self.mapSize[1] = int(self.response[1])

    def connect(self):
        try:
            self.client.connect()
            self.client.receive()
            self.client.send(self.teamName)
            self.response = self.client.receive().split("\n")
            if self.response[0] == "ko" or len(self.response) != 3:
                raise cEx.clientException("Error: team name is invalid")
        except Exception as e:
            print(e)

    def disconnect(self):
        try:
            self.client.disconnect()
        except Exception as e:
            print(e)

    def send(self, message):
        try:
            self.client.send(message)
            self.client.receive()
        except Exception as e:
            print(e)

    def receive(self):
        try:
            self.client.receive()
        except Exception as e:
            print(e)

    def getSocket(self):
        return self.client.getSocket()

    def getPort(self):
        return self.client.getPort()

    def getHost(self):
        return self.client.getHost()

    def getTeamName(self):
        return self.teamName

    def forward(self):
        self.send(cAct.FORWARD.value)

    def right(self):
        self.send(cAct.RIGHT.value)

    def left(self):
        self.send(cAct.LEFT.value)

    def look(self):
        self.client.send(cAct.LOOK.value)
        self.response = self.client.receive()

    def inventory(self):
        self.send(cAct.INVENTORY.value)

    def broadcast(self, message):
        self.send(cAct.BROADCAST.value + " " + message + "\n")

    def connectNbr(self):
        self.send(cAct.CONNECT_NBR.value)

    def fork(self):
        self.send(cAct.FORK.value)

    def eject(self):
        self.send(cAct.EJECT.value)

    def take(self, object):
        self.send(cAct.TAKE.value + " " + object + "\n")

    def set(self, object):
        self.send(cAct.SET.value + " " + object + "\n")

    def incantation(self):
        self.send(cAct.INCANTATION.value)

    def run(self):
        while self.alive:
            self.look()
            self.alive = False
