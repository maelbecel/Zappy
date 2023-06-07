/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** array_size
*/

#include "utils.h"

uint array_size(char **array)
{
    uint i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}
