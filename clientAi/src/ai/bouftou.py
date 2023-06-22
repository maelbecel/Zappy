##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## bouftou
##

from ..ai.clientAi import clientAi as clientAI


class bouftou(clientAI):
    def __init__(self, teamName, port, host, elementToGrab, bool):
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
        super().__init__(teamName, port, host, bool)
        self.safeFoodLevel = 10
        self.max = 10
        self.oldmax = 10
        self.startProcess = 3
        self.process = self.startProcess
        self.elementToGrab = elementToGrab

    def getElementToGrab(self):
        return self.elementToGrab

    def getProcess(self):
        return self.process

    def checkElementToGrab(self):
        """
        The function checks the type of element to grab and sets a process value
        accordingly.

        @return a boolean value. It returns True if the element to grab is one of
        "linemate", "deraumere", "sibur", "mendiane", "phiras", or "thystame", and
        sets the process variable to 2 or 3 depending on the element. It returns
        False if the element to grab is "food" or an invalid element.
        """
        if self.elementToGrab == "food":
            self.process = 3
            return True
        if (
            self.elementToGrab == "linemate"
            or self.elementToGrab == "deraumere"
            or self.elementToGrab == "sibur"
            or self.elementToGrab == "mendiane"
        ):
            self.process = 2
            return True
        if self.elementToGrab == "phiras" or self.elementToGrab == "thystame":
            self.process = 3
            return True
        return False

    def takeAllElementForHimself(self):
        """
        This function checks if a specific element is present and then takes it.

        @return If `self.lookResult[0]` is empty, then `None` is being returned.
        Otherwise, nothing is being returned explicitly, as the function ends after
        the `for` loop.
        """
        self.look()
        if not self.lookResult[0]:
            return
        for element in self.lookResult[0]:
            if element == self.elementToGrab:
                self.take(self.elementToGrab)

    def takeSomeFood(self):
        """
        This function allows a character to take all available food items in their
        vicinity.

        @return If the count of "food" in the lookResult is less than or equal to
        0, then nothing is returned. Otherwise, the function takes all the "food"
        items and sets the lookingForFood flag to False.
        """
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
        """
        This function iterates through the map and collects all elements of a
        certain type while moving forward, turning right, and turning left.

        @param x The x parameter is likely an index or key used to access the size
        of the map in the self.mapSize dictionary or list. It is used in the range
        function to iterate over the x-axis of the map.
        @param y The parameter "y" is likely representing the y-axis of the map or
        grid that the code is operating on. It is used in the nested for loop to
        iterate over all the elements in the y-axis of the map.
        """
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
        """
        This function throws a specified number of "food" elements if the current
        element to grab is not "food".

        @param count The number of times the code will execute the loop.
        """
        for i in range(0, count):
            if not self.elementToGrab == "food":
                self.take("food")
            self.set(self.elementToGrab)

    def dispatchAllElement(self):
        """
        This function dispatches all elements in a grid by throwing them and moving
        the robot forward.
        """
        self.inventory()

        elementToDispatch = int(
            self.inv[self.elementToGrab] / (self.mapSize[0] * self.mapSize[1])
        )

        for i in range(0, self.mapSize[0]):
            for j in range(0, self.mapSize[1]):
                self.throwElement(elementToDispatch)
                self.forward()
            self.right()
            self.forward()
            self.left()

    def dropAllOverElement(self):
        """
        The function drops excess food items if the safe food level has been
        reached and adjusts the safe food level accordingly.

        @return If `foodToThrow` is not greater than 0, then nothing is returned
        and the function ends. Otherwise, the function executes a loop to drop the
        excess food items and updates the `safeFoodLevel` variable. No explicit
        return statement is provided in this case, so the function implicitly
        returns `None`.
        """
        if self.elementToGrab == "food":
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
        """
        This function runs a loop that processes elements in the world and performs
        actions on them until the process counter reaches zero.
        """
        if not self.checkElementToGrab():
            return
        self.inventory()
        while self.alive:
            self.process -= 1
            if self.process <= 0:
                self.dispatchAllElement()
                continue
            self.getAllElementOfTheWorld(0, 1)
            self.dropAllOverElement()
            self.takeAllElementForHimself()
