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
from ..state.clientState import enumState as enumState
from ..front.rayCasting import rayCasting

MIN_FOOD = 10
PERCENTAGE_OF_FOOD = 0.5


class clientAi:
    def __init__(self, teamName: str, port: int, host: str, isGraphic):
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
        self.lookResult = []
        self.alive = True
        self.mapSize = [0, 0]
        self.response = None
        self.availablePlaces = 0
        self.teamName = teamName
        self.client = clientServer(port, host)
        self.direction = direction()
        self.queue = []
        self.inv = {
            "food": 10,
            "linemate": 0,
            "deraumere": 0,
            "sibur": 0,
            "mendiane": 0,
            "phiras": 0,
            "thystame": 0,
        }
        self.level = 1
        self.lookingForFood = False
        self.message = ""
        self.inputData = []
        self.state = 0
        self.graphic = isGraphic
        if self.graphic is True:
            self.initPygame()
        else:
            self.rayCasting = None

    def __del__(self):
        if self.graphic is True:
            rayCasting.pygame.quit()

    def initPygame(self):
        self.rayCasting = rayCasting(1200, 800)

    def getConnectionResponse(self):
        """
        This function parses a response from a server and extracts information
        about available places and map size.
        """
        if not self.alive:
            return
        self.availablePlaces = int(self.response[0])
        self.response = self.response[1].split(" ")
        if len(self.response) != 2:
            raise cEx("Error: map size is invalid")
        self.mapSize[0] = int(self.response[0])
        self.mapSize[1] = int(self.response[1])

    def connect(self):
        """
        This function attempts to connect to a client and sends a team name,
        raising an exception if the team name is invalid.
        """
        try:
            if not self.alive:
                return
            self.client.connect()
            self.client.receive()
            self.client.send(self.teamName + "\n")
            if not self.alive:
                return
            self.response = self.client.receive().split("\n")
            if self.response[0] == "ko" or len(self.response) != 3:
                raise cEx("Error: team name is invalid")
            self.getConnectionResponse()
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
        if not self.alive:
            return False
        self.client.send(message)
        if not self.receive():
            return False
        return True

    def receive(self):
        """
        This function attempts to receive data from a client and prints any
        exceptions that occur.
        """
        # try:
        if not self.alive:
            return False
        self.response = self.client.receive()
        print("Response: " + self.response)
        if self.response == "dead\n":
            self.alive = False
            return False
        elif self.response.find("message") != -1:
            print("Message: " + self.response)
            self.message = self.response
            try:
                values = self.response.split(";")
                value1 = values[0].split(",")[-1].strip()
                value2 = values[1]
                value3 = values[2][:-1]
                self.orientation = self.message.split(',')[0].split(' ')[-1].strip()
                if (value1 == self.teamName and value2 == "Incantation" and value3 == str(self.level)):
                    self.state = enumState.JOIN_INCANTATION
            except:
                pass
            self.receive()
        elif self.response.find("eject") != -1:
            # handle eject
            ...
        elif self.response.find("Current level: ") != -1:
            print("Get level: " + self.response.split(":")[1])
            self.level = int(self.response.split(":")[1])
            if (self.state == enumState.JOIN_INCANTATION):
                self.state = enumState.NEED_FOOD
                self.receive()
            self.state = enumState.NEED_FOOD
        elif self.response.find("Elevation underway") != -1:
            if (self.state == enumState.JOIN_INCANTATION):
                self.receive()
        return True

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
        if not self.alive:
            return
        self.send(cAct.FORWARD.value)
        if self.response == "ok\n" and self.alive:
            self.direction.updateCoord()

    def right(self):
        """
        This function sends a command to move the object to the right and updates
        the direction accordingly.
        """
        if not self.alive:
            return
        self.send(cAct.RIGHT.value)
        if self.response == "ok\n" and self.alive:
            self.direction.updateDirectionToRight()

    def left(self):
        """
        This function sends a "LEFT" command and updates the direction to the left
        if the response is "ok".
        """
        if not self.alive:
            return
        self.send(cAct.LEFT.value)
        if self.response == "ok\n" and self.alive:
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
        if not self.alive:
            return
        self.send(cAct.LOOK.value)
        if self.isValidArray() and self.alive:
            self.parseLook()
        if self.graphic is True:
            array = self.lookResult
            array = self.rayCasting.ArrayToArrayOfDict(array)
            self.rayCasting.refreshLookDisplay(array)

    def inventory(self):
        """
        This function sends a request for inventory information.
        """
        if not self.alive:
            return
        self.send(cAct.INVENTORY.value)
        if self.isValidArray() and self.alive:
            self.checkValidityInv()
            return

    def broadcast(self, message: str):
        """
        This function sends a broadcast message with a given string message.

        @param message The parameter "message" is a string that represents the
        message that will be broadcasted. It will be concatenated with the string
        value of the "BROADCAST" constant from the "cAct" enum class and a newline
        character, and then sent using the "send" method.
        """
        if not self.alive:
            return
        self.send(cAct.BROADCAST.value + " " + message + "\n")
        if self.response == "ok\n" and self.alive:
            print("broadcast -> %s" % self.response)

    def connectNbr(self):
        """
        This function sends a message to connect to neighboring nodes.
        """
        if not self.alive:
            return
        self.send(cAct.CONNECT_NBR.value)
        if self.response[:-1].isdigit() and self.alive:
            self.availablePlaces = int(self.response.split("\n")[0])

    def fork(self):
        """
        The function sends a fork command using the cAct enum value.
        """
        if not self.alive:
            return
        self.send(cAct.FORK.value)
        if self.response == "ok\n" and self.alive:
            return

    def eject(self):
        """
        The function "eject" sends a command to eject something.
        """
        if not self.alive:
            return
        self.send(cAct.EJECT.value)
        if self.response == "ok\n" and self.alive:
            return

    def take(self, object: str):
        """
        This function sends a command to take an object to a game server.

        @param object The "object" parameter in the "take" method is a string that
        represents the name or identifier of the object that the player wants to
        take in the game. This parameter is used to construct a command that will
        be sent to the game engine to execute the "take" action.
        """
        if not self.alive:
            return
        self.send(cAct.TAKE.value + " " + object + "\n")
        if self.response == "ok\n" and self.alive:
            if not self.inv.get(object):
                self.inv[object] = 1
            else:
                self.inv[object] += 1

    def set(self, object: str):
        """
        This function sends a message with a "SET" command and an object parameter.

        @param object The "object" parameter is a string that represents the object
        that needs to be set. It is passed as an argument to the "set" method of a
        class.
        """
        if not self.alive:
            return
        self.send(cAct.SET.value + " " + object + "\n")
        if self.response == "ok\n" and self.alive:
            self.inv[object] -= 1

    def incantation(self):
        """
        This function sends an incantation message using the value of
        cAct.INCANTATION.
        """
        if not self.alive:
            return
        self.send(cAct.INCANTATION.value)
        self.receive()
        if self.response != "ko\n" and self.alive:
            self.state = enumState.NEED_FOOD
            return True
        return False

    def run(self):
        """
        The function "run" is defined with an ellipsis as its body, indicating that
        it is not yet implemented.
        """
        if not self.alive:
            return
        while self.alive:
            self.broadcast("Hello World")
            self.grabFood()

    def resetFood(self, array):
        """
        This function resets the quantity of food in a dictionary based on the
        input array.

        @param array The parameter "array" is a list of tuples, where each tuple
        contains two elements. The first element is a string that represents the
        type of item (e.g. "food", "weapon", "armor"), and the second element is an
        integer that represents the quantity of that item. The function
        """
        if not self.alive:
            return
        for element in array:
            if element[0] == "food" and element[1].isnumeric():
                self.inv[element[0]] = int(element[1])
                break

    def checkValidityInv(self):
        """
        This function checks the validity of an inventory by comparing it with the
        current inventory and fills it if there is any discrepancy.
        """
        array = self.parseInv()

        if not self.alive:
            return
        self.resetFood(array)
        for element in array:
            if element[0] == "food":
                continue
            if (
                element[0]
                and element[0] in self.inv
                and self.inv[element[0]] != element[1]
            ):
                self.fillInv(array)
                break
        print("food -> %s" % self.inv["food"])

    def fillInv(self, array):
        """
        This function fills a dictionary called "inv" with key-value pairs from a
        given array.

        @param array The parameter "array" is a list of tuples, where each tuple
        contains two elements. The first element is a key and the second element is
        a value. The function "fillInv" takes this array and populates the "inv"
        dictionary of the object with the keys and values from the tuples
        """
        if not self.alive:
            return
        for element in array:
            if (element[1].isnumeric() == False):
                return
            self.inv[element[0]] = int(element[1])

    def parseInv(self):
        """
        This function parses an inventory response and returns a list of items.

        @return The function `parseInv` is returning a list of lists. Each inner
        list contains two elements: the first element is a string representing an
        item name, and the second element is an integer representing the quantity
        of that item. The function is parsing a string response and extracting the
        item names and quantities from it.
        """
        temp = []

        if not self.alive:
            return
        array = self.response[1:-3].split(",")
        for element in array:
            temp.append(element[1:].split(" "))

        return temp

    def isValidArray(self):
        """
        This function checks if a given response is a valid array in Python.

        @return This code defines a method called `isValidArray` that checks if a
        given response is a valid array. It returns `True` if the response is a
        valid array and `False` otherwise.
        """
        if not self.alive:
            return
        if (
            self.response
            and self.response[-1]
            and self.response[-2]
            and not self.response[-1] == "\n"
            and not self.response[-2] == "]"
        ):
            return False
        if not self.response[0] == "[":
            return False
        return True

    def parseLook(self):
        """
        This function parses a response string and appends the resulting array to a
        list.
        """
        if not self.alive:
            return
        array = self.response[1:-2].split(",")
        self.lookResult.clear()
        for i in range(0, len(array)):
            if i == len(array) - 1:
                self.lookResult.append(array[i][1:-1].split(" "))
                break
            self.lookResult.append(array[i][1:].split(" "))

    def computeQueueActions(self):
        """
        This function executes all the elements in a queue and then clears the
        queue.
        """
        if not self.alive:
            return
        for element in self.queue:
            if not self.alive:
                return
            element()
        self.queue.clear()

    def getGoTo(self, value: int):
        """
        The function calculates the coordinates of a cell in a grid based on a given
        value.

        @param value The value parameter is an integer that represents the target
        value to be reached in the function.
        """
        if not self.alive:
            return
        beforeSize = 1
        result = 0
        max = 0
        it = 2
        x = 0
        y = 0

        while result != value:
            if value == max:
                x += 1
                result += 1
                continue
            if result < value and value < max:
                x += 1
                result += 1
                continue
            elif result > value:
                x -= 1
                result -= 1
                continue
            beforeSize += 2
            max += beforeSize
            result += it
            it += 2
            y += 1

        self.fillQueue(x, y)

    def getQueue(self):
        return self.queue

    def fillQueue(self, x: int, y: int):
        """
        This function fills a queue with commands to move a robot a certain number
        of steps to the left or right, and a certain number of steps forward.

        @param x The parameter x represents the distance that the robot needs to
        move horizontally (either to the left or to the right). If x is negative,
        it means the robot needs to move to the left. If x is positive, it means
        the robot needs to move to the right.
        @param y The parameter "y" represents the number of times the robot should
        move forward. It is used in a for loop to append the "forward" command to
        the robot's queue.
        """
        if not self.alive:
            return
        left = False
        if x < 0:
            x *= -1
            left = True
        for i in range(0, y):
            self.queue.append(self.forward)
        if left:
            self.queue.append(self.left)
        elif x != 0:
            self.queue.append(self.right)
        for i in range(0, x):
            self.queue.append(self.forward)

    def pickObject(self, value, object: str):
        """
        This function picks up an object at a specified location.

        @param value It seems that the `value` parameter is used as an input to the
        `getGoTo()` method, which suggests that it might be a location or position
        that the object needs to move to. However, without more context or
        information about the code, it's difficult to say for sure.
        @param object The "object" parameter in the function "pickObject" is a
        string that represents the name or identifier of the object that the
        function is supposed to pick up.
        """
        if not self.alive:
            return
        self.getGoTo(value)
        self.computeQueueActions()
        self.take(object)

    def findFood(self):
        """
        The function finds the index of the first occurrence of the string "food"
        in a 2D array and returns it, or returns -1 if "food" is not found.

        @return The function `findFood` returns the index of the first occurrence
        of the string "food" in the 2D list `self.lookResult`. If "food" is not
        found in the list, it returns -1.
        """
        id = 0

        for array in self.lookResult:
            for element in array:
                if element == "food":
                    return id
            id += 1
        return -1

    def goElsewhere(self):
        """
        The function makes a robot move in a square pattern while searching for
        food and stops when it finds food.

        @return nothing (i.e., it does not have a return statement). It is using
        the `return` keyword inside a loop to exit the function early if certain
        conditions are met.
        """
        rotateId = 0

        while self.lookingForFood:
            if rotateId % 4 == 0:
                self.forward()
            self.left()
            self.look()
            result = self.findFood()
            if result != -1:
                self.getGoTo(result)
                self.computeQueueActions()
                return
            rotateId += 1

    def grabFood(self):
        """
        This function helps a character in a game grab food based on a certain
        percentage and their surroundings.

        @return If the condition in the if statement is true (meaning the agent
        does not need food), then nothing is returned and the function ends. If the
        condition is false, then the function executes the code block and takes
        food from the environment. No value is explicitly returned in this case.
        """
        count = 0
        result = 0

        if not self.alive:
            return
        if not self.needFood():
            self.state = enumState.LF_RESSOURCES
            return
        self.look()
        for element in self.lookResult[0]:
            if element == "food":
                count += 1
        if not count < 1:
            if count != 1:
                count *= PERCENTAGE_OF_FOOD
                count = round(count, 0)
            for i in range(0, int(count)):
                self.take("food")
                self.lookingForFood = False
                return
        else:
            result = self.findFood()
            if result == -1:
                self.getGoTo(result)
                self.computeQueueActions()
                self.grabFood()
                return
        self.goElsewhere()
        self.grabFood()

    def needFood(self):
        """
        This function checks if the player's inventory has enough food.

        @return a boolean value. If the value of "food" in the inventory is less
        than the minimum required amount (MIN_FOOD), then it returns True,
        indicating that the player needs food. Otherwise, it returns False,
        indicating that the player does not need food.
        """
        if not self.alive:
            return False
        self.inventory()
        if "food" in self.inv and self.inv["food"] < MIN_FOOD:
            self.lookingForFood = True
            return True
        return False
