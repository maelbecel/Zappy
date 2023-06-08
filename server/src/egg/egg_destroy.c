/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** egg_destroy
*/

#include <stdlib.h>
#include "server.h"

void egg_destroy(egg_t *egg)
{
    if (!egg)
        return;
    free(egg);
}
