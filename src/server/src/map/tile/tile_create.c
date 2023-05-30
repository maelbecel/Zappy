/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tile_create
*/

#include <stdlib.h>
#include "map.h"

tile_t *tile_create(uint x, uint y)
{
    tile_t *tile = calloc(1, sizeof(tile_t));

    if (!tile)
        return NULL;
    tile->x = x;
    tile->y = y;
    tile->players = olist_create();
    if (!tile->players) {
        free(tile);
        return NULL;
    }
    tile->inventory = inventory_create();
    if (!tile->inventory) {
        olist_destroy(tile->players);
        free(tile);
        return NULL;
    }
    return (tile);
}
