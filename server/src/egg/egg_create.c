/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** egg_create
*/

#include <stdlib.h>
#include "server.h"
#include "utils.h"

egg_t *egg_create(ulong team_id, uint x, uint y, ulong player_id)
{
    egg_t *egg = calloc(1, sizeof(egg_t));

    if (!egg)
        return NULL;
    egg->id = generate_id();
    egg->team_id = team_id;
    egg->x = x;
    egg->y = y;
    egg->player_id = player_id;
    egg->hatched = false;
    return egg;
}
