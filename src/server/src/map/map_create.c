/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map_create
*/

#include <stdlib.h>
#include "map.h"

map_t *map_create(uint width, uint height)
{
    map_t *map = calloc(1, sizeof(map_t));

    if (!map)
        return NULL;
    map->width = width;
    map->height = height;
    map->tiles = olist_create();
    for (uint y = 0; y < height; y++)
        for (uint x = 0; x < width; x++)
            olist_add_node(map->tiles, tile_create(x, y));
    return map;
}
