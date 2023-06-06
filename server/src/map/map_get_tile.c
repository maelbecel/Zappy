/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map_get_tile
*/

#include "map.h"

tile_t *map_get_tile(map_t *map, uint x, uint y)
{
    tile_t *tile = NULL;

    if (!map)
        return NULL;
    OLIST_FOREACH(map->tiles, node) {
        tile = node->data;
        if (tile->x == x && tile->y == y)
            return tile;
    }
    return NULL;
}
