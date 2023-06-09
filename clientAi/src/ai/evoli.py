##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## evoli
##

from ..ai.clientAi import clientAi as clientAI

# const tab that permise to know the number of ressources needed to evolve
# level 1 to 8
REQUIRED = [
    {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0},
    {"linemate": 1, "deraumere": 1, "sibur": 1, "mendiane": 0, "phiras": 0, "thystame": 0},
    {"linemate": 2, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 2, "thystame": 0},
    {"linemate": 1, "deraumere": 1, "sibur": 2, "mendiane": 0, "phiras": 1, "thystame": 0},
    {"linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3, "phiras": 0, "thystame": 0},
    {"linemate": 1, "deraumere": 2, "sibur": 3, "mendiane": 0, "phiras": 1, "thystame": 0},
    {"linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1}
]

REQUIRED_PLAYER = [
    1, 2, 2, 4, 4, 6, 6,
]

class evoli(clientAI):
    def __init__(self, teamName, port, host):
        super().__init__(teamName, port, host)
        self.objective = dict()

    def compareDict(self, dict1, dict2):

        if len(dict1) != len(dict2):
            print("The dictionaries are not equal")
        else:
            for key, value in dict1.items():
                if key not in dict2 or value < dict2[key]:
                    return False
            else:
                return True

    # check if there is a case with all the ressouce needed to evolve
    def checkRessourcesCases(self):
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
        temp = dict()

        self.look()
        temp = self.getDictFromCase(id)
        if self.compareDict(temp, REQUIRED[self.level - 1]):
            return True
        return False

    def takeUselessRessourcesOnCase(self):
        temp = dict()

        self.look()
        temp = self.getDictFromCase(0)
        # remove element from case
        for (key, value) in temp.items():
            if key in self.objective and value > self.objective[key]:
                for i in range(value - self.objective[key]):
                    self.take(key)

    def countPlayerOnCase(self):

        count = 0

        for element in self.lookResult[0]:
            if element == "player":
                count += 1
        return count

    def elevate(self):
        count = self.countPlayerOnCase()

        if count == REQUIRED_PLAYER[self.level - 1]:
            self.incantation()
        else:
            self.broadcast("need more player " + self.teamName)

    def findPlaceToElevate(self):
        index = 0

        index = self.checkRessourcesCases()

        print("index = ", index)

        if not index == -1:
            self.getGoTo(index)
            self.computeQueueActions()
            if self.checkActualCase(index): # check if the case is the good one
                self.takeUselessRessourcesOnCase()
                self.elevate()

    def run(self):

        while self.alive:
            self.findPlaceToElevate()
            self.alive = False
