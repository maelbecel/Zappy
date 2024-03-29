##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## clientAction
##

from enum import Enum


# The class "enumActions" defines a set of actions with corresponding string
# values.
class enumActions(Enum):
    FORWARD = "Forward\n"
    RIGHT = "Right\n"
    LEFT = "Left\n"
    LOOK = "Look\n"
    INVENTORY = "Inventory\n"
    BROADCAST = "Broadcast"
    CONNECT_NBR = "Connect_nbr\n"
    FORK = "Fork\n"
    EJECT = "Eject\n"
    TAKE = "Take"
    SET = "Set"
    INCANTATION = "Incantation\n"
