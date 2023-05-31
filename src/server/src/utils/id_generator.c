/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** id_generator
*/

#include "utils.h"

ulong generate_id(void)
{
    static ulong id = 1;

    return ++id;
}
