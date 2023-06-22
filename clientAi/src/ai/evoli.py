##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## evoli
##

from ..ai.clientAi import clientAi as clientAI
from ..state.clientState import enumState as enumState

# const tab that permise to know the number of ressources needed to evolve
# level 1 to 8
REQUIRED = [
    {
        "linemate": 1,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
    },
    {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
    },
    {
        "linemate": 2,
        "deraumere": 0,
        "sibur": 1,
        "mendiane": 0,
        "phiras": 2,
        "thystame": 0,
    },
    {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 2,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0,
    },
    {
        "linemate": 1,
        "deraumere": 2,
        "sibur": 1,
        "mendiane": 3,
        "phiras": 0,
        "thystame": 0,
    },
    {
        "linemate": 1,
        "deraumere": 2,
        "sibur": 3,
        "mendiane": 0,
        "phiras": 1,
        "thystame": 0,
    },
    {
        "linemate": 2,
        "deraumere": 2,
        "sibur": 2,
        "mendiane": 2,
        "phiras": 2,
        "thystame": 1,
    },
]

REQUIRED_PLAYER = [
    1,
    2,
    2,
    4,
    4,
    6,
    6,
]


class evoli(clientAI):
    def __init__(self, teamName, port, host, bool):
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
        self.objective = dict()
        self.state = enumState.NEED_FOOD

    def compareDict(self, dict1, dict2):
        """
        The function compares two dictionaries and returns True if they have the
        same keys and values, or False otherwise.

        @param dict1 The first dictionary to be compared.
        @param dict2 I'm sorry, but the code you provided is incomplete. It seems
        that the parameter dict2 is missing. Please provide the complete code or
        specify the value of dict2.

        @return a boolean value. It returns True if the two dictionaries have the
        same keys and values, or if the values in dict1 are greater than or equal
        to the corresponding values in dict2. It returns False if the two
        dictionaries have different keys or if the values in dict1 are less than
        the corresponding values in dict2. If the length of the two dictionaries is
        different, it
        """

        if len(dict1) != len(dict2):
            print("The dictionaries are not equal")
        else:
            for key, value in dict1.items():
                if key not in dict2 or value < dict2[key]:
                    return False
            else:
                return True

    def checkRessourcesCases(self):
        """
        This function checks if the resources in a game match the required
        resources for a certain level.

        @return an integer value, either the index of the first array in
        `self.lookResult` that matches the required resources for the current level
        (as defined in the `REQUIRED` dictionary), or -1 if no matching array is
        found.
        """
        index = 0

        self.look()

        for array in self.lookResult:
            self.objective = dict()
            for item in REQUIRED[self.level - 1]:
                self.objective[item] = 0
            for element in array:
                if element == "player" or element == "food":
                    continue
                if element in self.objective:
                    self.objective[element] += 1
                elif element:
                    self.objective[element] = 1
            if self.compareDict(self.objective, REQUIRED[self.level - 1]):
                return index
            index += 1
        return -1

    def getDictFromCase(self, id: int):
        """
        The function takes an integer ID and returns a dictionary with keys from a
        predefined list and values representing the frequency of those keys in a
        list of elements from a lookResult attribute.

        @param id The "id" parameter is an integer that represents the index of a
        specific case in the "lookResult" list. The function is designed to take
        this index and create a dictionary that counts the occurrences of certain
        elements in that case.

        @return The function `getDictFromCase` is returning a dictionary containing
        the count of each element in the `lookResult` list for a given `id`. The
        dictionary is initialized with keys from the `REQUIRED` list for the
        current level, and the values are initially set to 0. The function then
        iterates through the `lookResult` list for the given `id`, and increments
        the count
        """

        temp = dict()

        for item in REQUIRED[self.level - 1]:
            temp[item] = 0

        for element in self.lookResult[id]:
            if element == "player" or element == "food":
                continue
            if element in temp:
                temp[element] += 1
            elif element:
                temp[element] = 1

        return temp

    def checkActualCase(self, id: int):
        """
         The function checks if a given dictionary matches a required dictionary
        self.inputData = None based on a certain level.

         @param id The "id" parameter is an integer that represents the ID of a
         case.

         @return a boolean value. If the dictionary obtained from the case with the
         given id matches the required dictionary for the current level, then True
         is returned. Otherwise, False is returned.
        """
        temp = dict()

        self.look()
        temp = self.getDictFromCase(id)
        if self.compareDict(temp, REQUIRED[self.level - 1]):
            return True
        return False

    def takeUselessRessourcesOnCase(self):
        """
        The function removes excess resources from a case based on a required
        amount for a certain level.
        """
        temp = dict()

        # self.look()
        temp = self.getDictFromCase(0)

        # remove element from case
        for key, value in temp.items():
            if key in temp and value > REQUIRED[self.level - 1][key]:
                for i in range(value - REQUIRED[self.level - 1][key]):
                    self.take(key)

    def countPlayerOnCase(self):
        """
        This function counts the number of "player" elements in the first element
        of a list called "lookResult".

        @return the count of the number of times the string "player" appears in the
        first element of the list `self.lookResult`.
        """
        count = 0

        for element in self.lookResult[0]:
            if element == "player":
                count += 1
        return count

    def elevate(self):
        """
        This function checks if there are enough players on a game board case to
        perform an incantation and elevates the player's level if successful.

        @return nothing (i.e., `None`). It is using recursion to call itself until
        the `if` condition is met, and then it stops and returns nothing.
        """
        count = self.countPlayerOnCase()

        print("count = " + str(count))
        print("required = " + str(REQUIRED_PLAYER[self.level - 1]))
        if count == REQUIRED_PLAYER[self.level - 1]:
            if self.level == 2:
                self.broadcast("elevate to level 3")
            if not self.incantation():
                self.takeUselessRessourcesOnCase()
                self.elevate()
                return
        else:
            self.broadcast(self.teamName + ";Incantation;" + str(self.level))

    def findPlaceToElevate(self):
        """
        This function finds a place to elevate and performs the necessary actions.
        """
        index = 0

        index = self.checkRessourcesCases()

        if index != -1:
            print("found a case to elevate")
            self.getGoTo(index)
            self.computeQueueActions()
            if self.checkActualCase(0):  # check if the case is the good one
                self.takeUselessRessourcesOnCase()
                self.elevate()

    def gotAllNeededResource(self):
        """
        This function checks if the player has all the required resources to
        upgrade their level in a game.

        @return a boolean value. It returns True if the player has all the required
        resources for their current level, and False if they do not have all the
        required resources.
        """

        for element in self.inv:
            if element == "food":
                continue
            if self.inv[element] < REQUIRED[self.level - 1][element]:
                self.state = enumState.LF_RESSOURCES
                return False
        self.state = enumState.FULL_RESSOUCRES
        return True

    def findNeededRessources(self):
        """
        The function finds and picks up needed resources based on the player's
        inventory and level.

        @return a boolean value. If the player has all the needed resources, it
        returns True. Otherwise, it goes through the look results and picks up any
        resources that the player needs but does not have enough of, and then
        returns False.
        """
        id = 0

        self.look()

        if self.gotAllNeededResource():
            return True
        else:
            for array in self.lookResult:
                for element in array:
                    if element == "player" or element == "food":
                        continue
                    if (
                        element in self.inv
                        and self.inv[element] < REQUIRED[self.level - 1][element]
                    ):
                        self.pickObject(id, element)
                        return False
                id += 1
        return False

    def checkPlayerInFront(self):
        self.look()
        if "player" in self.lookResult[2]:
            return True
        return False

    def joinIncantation(self):
        orientation = self.message.split(",")[0].split(" ")[-1].strip()
        print("orientation : " + orientation)
        if orientation == "0":
            if self.countPlayerOnCase() == 2:
                exit(0)
            if self.countPlayerOnCase() == 1:
                while self.checkPlayerInFront() == False:
                    self.left()
                self.forward()
        elif orientation == "1":
            print("count = " + str(self.countPlayerOnCase()))
            if self.countPlayerOnCase() == 2:
                exit(0)
            self.forward()
        elif orientation == "2":
            self.forward()
            self.left()
            self.forward()
        elif orientation == "3":
            self.left()
            self.forward()
        elif orientation == "4":
            self.left()
            self.forward()
            self.left()
            self.forward()
        elif orientation == "5":
            self.left()
            self.left()
            self.forward()
        elif orientation == "6":
            self.right()
            self.forward()
            self.right()
            self.forward()
        elif orientation == "7":
            self.right()
            self.forward()
        elif orientation == "8":
            self.forward()
            self.right()
            self.forward()

    def placeRessources(self):
        """
        This function places resources on a case based on the player's inventory
        and level.
        """
        for element in self.inv:
            if element == "food":
                continue
            for i in range(self.inv[element]):
                if REQUIRED[self.level - 1][element] > 0:
                    for j in range(REQUIRED[self.level - 1][element]):
                        self.set(element)

    def run(self):
        """
        This function runs a loop where the object finds a place to elevate, grabs
        food, and repeats while alive.
        """
        while self.alive:
            # self.findPlaceToElevate()
            # self.findNeededRessources()
            # self.grabFood()
            print("state = " + str(self.state) + "\n")
            if (
                self.state == enumState.LF_RESSOURCES
                or self.state == enumState.NEED_FOOD
            ):
                self.findPlaceToElevate()
                self.findNeededRessources()
                self.grabFood()
            elif self.state == enumState.FULL_RESSOUCRES:
                self.placeRessources()
                self.elevate()
            elif self.state == enumState.JOIN_INCANTATION:
                self.joinIncantation()
                # self.grabFood()
