/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** array_size
*/

#include "utils.h"

/**
 * The function returns the size of a given array of strings.
 *
 * @param array A pointer to a pointer of characters, which
 * represents an array of strings.
 *
 * @return The function `array_size` returns the number of
 * elements in the array of strings `array`. If `array` is
 * `NULL`, it returns 0.
 */
uint array_size(char **array)
{
    uint i = 0;

    if (!array)
        return 0;
    for (; array[i]; i++);
    return i;
}
