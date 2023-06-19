##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## bouftou
##

from ..ai.clientAi import clientAi as clientAI


class bouftou(clientAI):
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
        self.safeFoodLevel = 10
        self.max = 10
        self.oldmax = 10
        self.process = 4

    def takeAllFoodForHimself(self):
        self.look()

        if not self.lookResult[0]:
            return
        for element in self.lookResult[0]:
            if element == "food":
                self.take("food")

    def getAllFoodOfTheWorld(self, x, y):
        for i in range(0, self.mapSize[x]):
            for j in range(0, self.mapSize[y]):
                self.takeAllFoodForHimself()
                self.forward()
            self.right()
            self.forward()
            self.left()

    def throwFood(self, count):
        for i in range(0, count):
            self.set("food")

    def dispatchAllFood(self):
        self.inventory()

        foodToDispatch = int(self.inv["food"] / (self.mapSize[0] * self.mapSize[1]))

        for i in range(0, self.mapSize[0]):
            for j in range(0, self.mapSize[1]):
                self.throwFood(foodToDispatch)
                self.forward()
            self.right()
            self.forward()
            self.left()

    def dropAllOverFood(self):
        print("aa")
        self.inventory()
        print("bb")
        self.max = self.inv["food"]
        print("number of food -> ", self.inv["food"])
        print("self.safeFoodLevel -> ", self.safeFoodLevel)
        foodToThrow = self.inv["food"] - self.safeFoodLevel
        print("food to throw -> ", foodToThrow)
        if not foodToThrow > 0:
            return

        for i in range(0, foodToThrow):
            self.set("food")
        self.safeFoodLevel *= int(int(self.max) / int(self.oldmax))
        self.oldmax = self.max

    def run(self):
        print("I'm a bouftou")
        print("map size -> ", self.mapSize)
        self.inventory()
        while self.alive:
            self.process -= 1
            if self.process <= 0:
                self.dispatchAllFood()
                continue
            self.getAllFoodOfTheWorld(0, 1)
            self.dropAllOverFood()
            self.getAllFoodOfTheWorld(1, 0)
            self.dropAllOverFood()
