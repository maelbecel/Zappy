##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## bouftou
##

from ..ai.clientAi import clientAi as clientAI
from ..ai.clientAi import PERCENTAGE_OF_FOOD


class bouftou(clientAI):
    def __init__(self, teamName, port, host, elementToGrab):
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
        self.safeFoodLevel = 10
        self.max = 10
        self.oldmax = 10
        self.startProcess = 3
        self.process = self.startProcess
        self.elementToGrab = elementToGrab

    def checkElementToGrab(self):

        if self.elementToGrab == "food":
            self.process = 3
        if (
            self.elementToGrab == "linemate"
            or self.elementToGrab == "deraumere"
            or self.elementToGrab == "sibur"
            or self.elementToGrab == "mendiane"
        ):
            self.process = 2
            return True
        if (
            self.elementToGrab == "phiras"
            or self.elementToGrab == "thystame"
        ):
            self.process = 3
            return True
        return False

    def takeAllElementForHimself(self):

        self.look()
        if not self.lookResult[0]:
            return
        for element in self.lookResult[0]:
            if element == self.elementToGrab:
                self.take(self.elementToGrab)

    def takeSomeFood(self):

        count = 0
        self.look()
        for element in self.lookResult[0]:
            if element == "food":
                count += 1
        if int(count) <= 0:
            self.lookingForFood = True
            return
        for i in range(0, int(count)):
            self.take("food")

        self.lookingForFood = False

    def getAllElementOfTheWorld(self, x, y):
        for i in range(0, self.mapSize[x]):
            for j in range(0, self.mapSize[y]):
                if not self.elementToGrab == "food":
                    self.take("food")
                self.takeAllElementForHimself()
                self.forward()
            self.right()
            self.forward()
            self.left()

    def throwElement(self, count):
        for i in range(0, count):
            if not self.elementToGrab == "food":
                self.take("food")
            self.set(self.elementToGrab)

    def dispatchAllElement(self):
        self.inventory()

        elementToDispatch = int(self.inv[self.elementToGrab] / (self.mapSize[0] * self.mapSize[1]))

        for i in range(0, self.mapSize[0]):
            for j in range(0, self.mapSize[1]):
                self.throwElement(elementToDispatch)
                self.forward()
            self.right()
            self.forward()
            self.left()

    def dropAllOverElement(self):
        if (self.elementToGrab == "food"):
            self.inventory()
            self.max = self.inv[self.elementToGrab]
            foodToThrow = self.inv[self.elementToGrab] - self.safeFoodLevel
            if not foodToThrow > 0:
                return
            for i in range(0, foodToThrow):
                self.set(self.elementToGrab)
            if self.startProcess - 1 == self.process:
                self.safeFoodLevel *= int((int(self.max) / int(self.oldmax)) / 1.2)
            else:
                self.safeFoodLevel *= int(int(self.max) / int(self.oldmax))
            self.oldmax = self.max
        else:
            for i in range(0, self.inv[self.elementToGrab]):
                self.set(self.elementToGrab)

    def run(self):
        self.inventory()
        while self.alive:
            self.process -= 1
            if self.process <= 0:
                self.dispatchAllElement()
                continue
            self.getAllElementOfTheWorld(0, 1)
            self.dropAllOverElement()
            self.takeAllElementForHimself()
