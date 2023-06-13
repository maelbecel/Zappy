##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## clientState
##

from enum import Enum


# The above class defines an enumeration of three states: NEED_FOOD,
# LF_RESSOURCES, and FULL_RESSOURCES.
class enumState(Enum):
    NEED_FOOD = 0
    LF_RESSOURCES = 1
    FULL_RESSOUCRES = 2
