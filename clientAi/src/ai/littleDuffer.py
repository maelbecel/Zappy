##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## littleDuffer
##

from ..ai.clientAi import clientAi as clientAI


class littleDuffer(clientAI):
    def __init__(self, teamName, port, host):
        """
        This is a constructor method that initializes the attributes of an object
        with a team name, port, host, objective dictionary, and state.

        @param teamName The name of the team that the code is being written for.
        @param port The port number is a communication endpoint used by a computer
        network to identify a specific process to which a message or data packet is
        to be delivered. In this case, it is likely referring to the port number
        that the program will use to establish a connection with another device or
        server.
        @param host The "host" parameter is a string that represents the IP address
        or hostname of the server that the code is connecting to. It is used to
        establish a network connection between the client and the server.
        """
        super().__init__(teamName, port, host)

    def checkTeam(self):
        """
        This function checks if a team name is present in a given message and
        returns True if it is, False otherwise.

        @return a boolean value. If the team name is found in the message, it
        returns True. Otherwise, it returns False.
        """

        if self.message.find(self.teamName) == -1:
            return False
        return True

    def repeatWhatPeopleSay(self):
        """
        This function broadcasts a message if the team is not checked and the
        message is not empty.
        """
        if not self.checkTeam() and self.message != "":
            self.broadcast(self.message)

    def run(self):
        """
        This function runs a loop where the object grabs food and repeats what
        people say while it is alive.
        """
        while self.alive:
            self.grabFood()
            self.repeatWhatPeopleSay()
