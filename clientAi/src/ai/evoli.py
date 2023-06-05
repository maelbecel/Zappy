##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## evoli
##

from ..ai.clientAi import clientAi as clientAI


class evoli(clientAI):
    def __init__(self, teamName, port, host):
        super().__init__(teamName, port, host)
        self.queue = []

    def run(self):
        while self.alive:
            self.look()

    def __getGoTo(self, value):
        x, y, max, result = 0
        beforeSize = 1
        it = 2

        while result != value:
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

        self.__fillQueue(x, y)

    def __fillQueue(self, x, y):
        left = False

        if x < 0:
            x *= -1
            left = True
        for i in range(0, y):
            self.queue.append(self.forward)
        if left:
            self.queue.append(self.left)
        else:
            self.queue.append(self.right)
        for i in range(0, x):
            self.queue.append(self.forward)
