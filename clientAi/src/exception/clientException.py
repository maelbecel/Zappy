##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## clientException
##


class clientException(Exception):
    def __init__(self, message):
        self.message = message
        super().__init__(self.message)
