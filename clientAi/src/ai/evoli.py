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

    def run(self):
        while self.alive:
            self.look()
