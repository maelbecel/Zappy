##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## clientAi
##

# These lines are importing specific classes and enums from other modules in the
# project.
from ..action.clientAction import enumActions as cAct
from ..exception.clientException import clientException as cEx
from ..server.clientServer import clientServer
from ..direction.direction import direction


class clientAi:
    def __init__(self, teamName: str, port: int, host: str):
        """
        This is the initialization function for a client AI that sets up various
        attributes and creates a client server object.

        @param teamName A string representing the name of the team that the AI
        client belongs to.
        @param port The port number on which the client will connect to the server.
        It is a communication endpoint that identifies a specific process to which
        the client will connect.
        @param host The host parameter is a string that represents the IP address
        or hostname of the server that the client will connect to.
        """
        print("Init clientAi")
        self.alive = True
        self.mapSize = [0, 0]
        self.response = None
        self.availablePlace = 0
        self.teamName = teamName + "\n"
        self.client = clientServer(port, host)
        self.direction = direction()

    def getConnectionResponse(self):
        """
        This function parses a response from a server and extracts information
        about available places and map size.
        """
        self.availablePlace = int(self.response[0])
        self.response = self.response[1].split(" ")
        if len(self.response) != 2:
            raise cEx.clientException("Error: map size is invalid")
        self.mapSize[0] = int(self.response[0])
        self.mapSize[1] = int(self.response[1])

    def connect(self):
        """
        This function attempts to connect to a client and sends a team name,
        raising an exception if the team name is invalid.
        """
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
        """
        This function attempts to disconnect a client and prints any exceptions
        that occur.
        """
        try:
            self.client.disconnect()
        except Exception as e:
            print(e)

    def send(self, message: str):
        """
        This function sends a message using a client and receives a response,
        handling any exceptions that may occur.

        @param message The parameter "message" is a string that represents the
        message that the client wants to send to the server.
        """
        try:
            self.client.send(message)
            self.response = self.client.receive()
        except Exception as e:
            print(e)

    def receive(self):
        """
        This function attempts to receive data from a client and prints any
        exceptions that occur.
        """
        try:
            self.client.receive()
        except Exception as e:
            print(e)

    def getSocket(self):
        """
        This function returns the socket object of a client.

        @return The `getSocket()` method of the `client` object is being called and
        its return value is being returned.
        """
        return self.client.getSocket()

    def getPort(self):
        """
        This function returns the port number of a client.

        @return The `getPort()` method of the `client` object is being called and
        its return value is being returned by the `getPort()` method of the current
        object. The specific value being returned depends on the implementation of
        the `getPort()` method in the `client` object.
        """
        return self.client.getPort()

    def getHost(self):
        """
        This function returns the host of a client.

        @return The `getHost()` method of the `client` object is being called and
        its return value is being returned by the `getHost()` method of the current
        object. The return value is likely the hostname or IP address of the
        client.
        """
        return self.client.getHost()

    def getTeamName(self):
        """
        This function returns the name of a team.

        @return The method `getTeamName` is returning the value of the `teamName`
        attribute of the object.
        """
        return self.teamName

    def forward(self):
        """
        This function sends a command to move forward.
        """
        self.send(cAct.FORWARD.value)
        self.direction.upadteCoord()

    def right(self):
        """
        This function sends a command to move the object to the right and updates
        the direction accordingly.
        """
        self.send(cAct.RIGHT.value)
        if self.response == "ok\n":
            self.direction.updateDirectionToRight()

    def left(self):
        """
        This function sends a "LEFT" command and updates the direction to the left
        if the response is "ok".
        """
        self.send(cAct.LEFT.value)
        if self.response == "ok\n":
            self.direction.updateDirectionToLeft()

    def look(self):
        """
        This function sends a "look" command to a client and returns the response
        received.

        @return The `look()` method is returning the response received from the
        server after sending the `LOOK` command. The specific content of the
        response depends on the implementation of the server and the game being
        played.
        """
        self.client.send(cAct.LOOK.value)
        self.response = self.client.receive()
        return self.response

    def inventory(self):
        """
        This function sends a request for inventory information.
        """
        self.send(cAct.INVENTORY.value)

    def broadcast(self, message: str):
        """
        This function sends a broadcast message with a given string message.

        @param message The parameter "message" is a string that represents the
        message that will be broadcasted. It will be concatenated with the string
        value of the "BROADCAST" constant from the "cAct" enum class and a newline
        character, and then sent using the "send" method.
        """
        self.send(cAct.BROADCAST.value + " " + message + "\n")

    def connectNbr(self):
        """
        This function sends a message to connect to neighboring nodes.
        """
        self.send(cAct.CONNECT_NBR.value)

    def fork(self):
        """
        The function sends a fork command using the cAct enum value.
        """
        self.send(cAct.FORK.value)

    def eject(self):
        """
        The function "eject" sends a command to eject something.
        """
        self.send(cAct.EJECT.value)

    def take(self, object: str):
        """
        This function sends a command to take an object to a game server.

        @param object The "object" parameter in the "take" method is a string that
        represents the name or identifier of the object that the player wants to
        take in the game. This parameter is used to construct a command that will
        be sent to the game engine to execute the "take" action.
        """
        self.send(cAct.TAKE.value + " " + object + "\n")

    def set(self, object: str):
        """
        This function sends a message with a "SET" command and an object parameter.

        @param object The "object" parameter is a string that represents the object
        that needs to be set. It is passed as an argument to the "set" method of a
        class.
        """
        self.send(cAct.SET.value + " " + object + "\n")

    def incantation(self):
        """
        This function sends an incantation message using the value of
        cAct.INCANTATION.
        """
        self.send(cAct.INCANTATION.value)

    def run(self):
        """
        The function "run" is defined with an ellipsis as its body, indicating that
        it is not yet implemented.
        """
        ...
