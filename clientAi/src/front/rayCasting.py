##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## rayCasting
##

import pygame

EXAMPLE_DATA = [
    {"linemate": 0, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0, "player": 0, "food": 0},
    {"linemate": 1, "deraumere": 1, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0, "player": 1, "food": 0},
    {"linemate": 1, "deraumere": 1, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0, "player": 1, "food": 0},
    {"linemate": 1, "deraumere": 1, "sibur": 0, "mendiane": 2, "phiras": 0, "thystame": 0, "player": 1, "food": 0},
]

ASSETS = {
    "linemate": "src/front/assets/linemate.png",
    "deraumere": "src/front/assets/deraumere.png",
    "sibur": "src/front/assets/sibur.png",
    "mendiane": "src/front/assets/mendiane.png",
    "phiras": "src/front/assets/phiras.png",
    "thystame": "src/front/assets/thystame.png",
    "player": "src/front/assets/player.png",
    "floor": "src/front/assets/grass.png",
    "player": "src/front/assets/player.png"
}

class rayCasting():
    def __init__(self, widht, height):
        # Initialize pygame
        pygame.init()
        self.caseSize = 90 # Size of each case (adjust as needed)
        self.width = widht
        self.height = height
        self.screen = pygame.display.set_mode((self.width, self.height))
        self.IsTwoD = True
        self.scaleRate = 3
        self.loadAllAssets()
        pygame.display.set_caption("Ray Casting Test")

    def loadAllAssets(self):
        for item, value in ASSETS.items():
            ASSETS[item] = self.loadImage(value)
            if item == "floor":
                ASSETS[item] = pygame.transform.scale(ASSETS[item], (self.caseSize, self.caseSize))
            else:
                ASSETS[item] = pygame.transform.scale(ASSETS[item], (self.caseSize / self.scaleRate, self.caseSize / self.scaleRate))

    def loadImage(self, filename):
        return pygame.image.load(filename)

    def renderCase2D(self, case, x, y):
        floor_image = ASSETS["floor"]
        self.screen.blit(floor_image, (x, y))
        originX = x

        for item, value in case.items():
            if not value > 0:
                continue
            asset = ASSETS.get(item)
            if asset:
                self.screen.blit(asset, (x, y))
                x += self.caseSize / self.scaleRate
                if x + self.caseSize / 2 > originX + self.caseSize:
                    x = originX
                    y += self.caseSize / self.scaleRate

    def render_array(self, array):
        y = self.height - self.caseSize
        x = self.width / 2 - self.caseSize / 2
        sizeLine = 1
        midleX = x
        id = 0
        i = 0

        while i < sizeLine:
            if id >= len(array):
                break
            case = array[id]
            id += 1
            if self.IsTwoD:
                self.renderCase2D(case, x, y)
            x += self.caseSize
            if i + 1 == sizeLine:
                i = 0
                sizeLine += 2
                x = midleX - (self.caseSize * int(sizeLine / 2))
                y -= self.caseSize
                continue
            i += 1

    def ArrayToArrayOfDict(self, array):
        temp = []

        for element in array:
            tempDict = dict()
            for item in element:
                if not item in tempDict and not item == "":
                    tempDict[item] = 1
                elif not item == "":
                    tempDict[item] += 1
            temp.append(tempDict)
        return temp

    def refreshLookDisplay(self, array):
        self.screen.fill((0, 0, 0))
        self.render_array(array)
        pygame.display.flip()

# this method as to be runned at the same location that the main.py
if __name__ == "__main__":
    rayCasting = rayCasting(1200, 800)
    running = True

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        rayCasting.refreshLookDisplay(EXAMPLE_DATA)
    pygame.quit()
