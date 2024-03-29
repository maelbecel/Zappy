/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tile_remove_player
*/

#include "map.h"
#include "ai.h"

void tile_remove_player(map_t *map, client_t *client)
{
    ai_t *ai = NULL;
    tile_t *tile = NULL;

    if (!map || !client)
        return;
    ai = client->data;
    if (!ai)
        return;
    tile = map_get_tile(map, ai->x, ai->y);
    if (!tile)
        return;
    tile->players--;
}
