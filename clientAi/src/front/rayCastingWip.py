##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## rayCasting
##

import pygame
import numpy as np

EXAMPLE_DATA = [
    {
        "linemate": 0,
        "deraumere": 0,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
        "player": 0,
        "food": 0,
    },
    {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
        "player": 1,
        "food": 0,
    },
    {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 0,
        "mendiane": 0,
        "phiras": 0,
        "thystame": 0,
        "player": 1,
        "food": 0,
    },
    {
        "linemate": 1,
        "deraumere": 1,
        "sibur": 0,
        "mendiane": 2,
        "phiras": 0,
        "thystame": 0,
        "player": 1,
        "food": 0,
    },
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
    "player": "src/front/assets/player.png",
}

class rayCasting:
    def __init__(self, widht, height):
        # Initialize pygame
        pygame.init()
        self.caseSize = 90  # Size of each case (adjust as needed)
        self.width = widht
        self.height = height
        self.screen = pygame.display.set_mode((1200, 800))
        self.IsTwoD = True
        self.scaleRate = 1
        self.dictSize = dict()
        self.loadAllAssets()
        self.dictScaling = dict()

        ##########
        self.clock = pygame.time.Clock()
        self.hres = 70 # horizontal resolution
        self.halfvres = 70 # half the vertical resolution
        self.mod = self.hres / 60 # scaling factor (60 * fov)
        self.posX = 0
        self.posY = 0
        self.rot = 0
        self.frame = np.random.uniform(0,1, (self.hres, self.halfvres * 2, 3)) # frame is the image that will be displayed
        self.sky = pygame.image.load('src/front/assets/skybox0.png')
        self.sky = pygame.surfarray.array3d(pygame.transform.scale(self.sky, (360, self.halfvres * 2))) / 255 # sky is the skybox, it is a 2D array of RGB values
        self.floor = pygame.image.load('src/front/assets/grassRC.png')
        self.sizeSprite = self.floor.get_width()
        self.floor = pygame.surfarray.array3d(pygame.image.load('src/front/assets/grassRC.png')) / 255
        ##########

    def loadImage(self, filename):
        return pygame.image.load(filename)

    def loadAllAssets(self):
        for item, value in ASSETS.items():
            img = self.loadImage(value)
            size = img.get_size()
            ASSETS[item] = img
            if item == "floor":
                ASSETS[item] = pygame.transform.scale(
                    ASSETS[item], (self.caseSize, self.caseSize)
                )
            else:
                self.dictSize[item] = np.asarray(img.get_size())
                print(self.dictSize[item])
                ASSETS[item] = pygame.transform.scale(
                    ASSETS[item],
                    (self.caseSize / self.scaleRate, self.caseSize / self.scaleRate),
                )

    def new_frame(self):
        for i in range(self.hres): # for each column of horizontal resolution (angle of view)
            rot_i = self.rot + np.deg2rad(i / self.mod - 30) # angle of the ray
            sin = np.sin(rot_i) # sin of the ray
            cos = np.cos(rot_i) # cos of the ray
            cos2 = np.cos(np.deg2rad(i / self.mod - 30)) # cos of the ray (used for the floor)
            self.frame[i][:] = self.sky[int(np.rad2deg(rot_i) % 359)][:] # skybox
            for j in range(self.halfvres): # for each pixel of vertical resolution
                n = (self.halfvres / (self.halfvres - j)) / cos2
                x = self.posX + cos * n
                y = self.posY + sin * n
                xx = int(x * 2 % 1 * self.sizeSprite)
                yy = int(y * 2 % 1 * self.sizeSprite)
                if xx > 4 and yy > 4:
                    shade = 0.2 + 0.8 * (1 - j / self.halfvres)
                    self.frame[i][self.halfvres * 2 - j - 1] = shade * self.floor[xx][yy]
                    if  int(x) % 3 == 0 and int(y) % 3 == 0:
                        self.frame[i][self.halfvres * 2 - j - 1] *= 0.5
                else:
                    self.frame[i][self.halfvres * 2 - j - 1] = 0
                    continue

        return self.frame

    def movement(self, keys):

        et = self.clock.tick()

        if keys[pygame.K_LEFT] or keys[ord('a')]:
            self.rot = self.rot - 0.001 * et

        if keys[pygame.K_RIGHT] or keys[ord('d')]:
            self.rot = self.rot + 0.001 * et

        if keys[pygame.K_UP] or keys[ord('w')]:
            self.posX, self.posY = self.posX + np.cos(self.rot) * 0.002 * et,  self.posY + np.sin(self.rot) * 0.002 * et

        if keys[pygame.K_DOWN] or keys[ord('s')]:
            self.posX, self.posY = self.posX - np.cos(self.rot) * 0.002 * et,  self.posY - np.sin(self.rot) * 0.002 * et

    def renderCase2D(self, case, x, y):
        # floor_image = ASSETS["floor"]
        # self.screen.blit(floor_image, (x, y))
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

    def displayAssets(self, data):

        # get coodinates of the player
        x = self.posX
        y = self.posY

        for element in data:
            x += self.caseSize
            self.renderCase2D(element, x, y)
            # self.screen.blit(ASSETS["floor"], (x,y))

# this method as to be runned at the same location that the main.py
if __name__ == "__main__":
    rayCasting = rayCasting(1200, 800)
    running = True

    # rayCasting.new_frame = rayCasting.new_frame

    sprite = pygame.image.load("src/front/assets/player.png")
    size = np.asarray(sprite.get_size())
    print(size)
    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
        rayCasting.movement(pygame.key.get_pressed())
        frame = rayCasting.new_frame()

        surf = pygame.surfarray.make_surface(frame * 255)
        surf = pygame.transform.scale(surf, (1200, 800))
        fps = int(rayCasting.clock.get_fps())
        pygame.display.set_caption("Pycasting maze - FPS: " + str(fps))

        rayCasting.screen.blit(surf, (0,0))
        mousePose = pygame.mouse.get_pos()
        # 100 is the max size of the player

        proportion = size[0] / size[1]

        scaling = size * abs((mousePose[1] - rayCasting.height / 2) / 10)
        print(scaling)
        if (scaling[1] > 350 and scaling[0] > 350):
            print("ok")
            scaling = np.asarray([350, 350])
        temp = pygame.transform.scale(sprite, scaling)  # scale the player
        rayCasting.screen.blit(temp, (mousePose - scaling / 2))
        rayCasting.displayAssets(EXAMPLE_DATA)
        pygame.display.update()
        # rayCasting.refreshLookDisplay(EXAMPLE_DATA)
    pygame.quit()
