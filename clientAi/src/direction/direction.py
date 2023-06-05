##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## direction
##

from enum import Enum


# The class "enumActions" defines a set of actions with corresponding string
# values.
class enumDirection(Enum):
    NORTH = 0
    EAST = 1
    SOUTH = 2
    WEST = 3


class direction:
    def __init__(self):
        """
        This is the initialization function for a class that sets the direction
        attribute to the value of enumDirection.NORTH.
        """
        self.direction = enumDirection.NORTH

    def getDirection(self):
        """
        This function returns the direction attribute of an object.

        @return The method `getDirection` is being defined for a class, and it
        returns the value of the instance variable `direction`.
        """
        return self.direction

    def updateDirectionToLeft(self):
        """
        This function updates the direction to the left based on the current
        direction.
        """
        if self.direction == enumDirection.NORTH:
            self.direction = enumDirection.EAST
        else:
            self.direction = enumDirection(self.direction.value - 1)

    def updateDirectionToRight(self):
        """
        This function updates the direction to the right based on the current
        direction.
        """
        if self.direction == enumDirection.EAST:
            self.direction = enumDirection.NORTH
        else:
            self.direction = enumDirection(self.direction.value + 1)
