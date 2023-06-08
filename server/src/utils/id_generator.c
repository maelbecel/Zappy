/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** id_generator
*/

#include "utils.h"

/**
 * The function generates a unique ID number each time it is called.
 *
 * @return The function `generate_id` returns an unsigned long integer
 * value, which is the incremented value of the static variable `id`.
 * The first time the function is called, it will return 2, and each
 * subsequent call will return the next incremented value.
 */
ulong generate_id(void)
{
    static ulong id = 1;

    return ++id;
}
