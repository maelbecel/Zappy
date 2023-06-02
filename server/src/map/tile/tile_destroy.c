/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tile_destroy
*/

#include <stdlib.h>
#include "map.h"

void tile_destroy(tile_t *tile)
{
    if (!tile)
        return;
    if (tile->players)
        olist_destroy(tile->players);
    if (tile->inventory)
        inventory_destroy(tile->inventory);
    free(tile);
}
