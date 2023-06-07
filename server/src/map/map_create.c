/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map_create
*/

#include <stdlib.h>
#include "map.h"

static void map_tile_destructor(olist_t *list)
{
    if (!list)
        return;
    OLIST_FOREACH(list, node) {
        tile_t *tile = node->data;
        if (tile)
            tile_destroy(tile);
    }
    olist_clear_wdfree(list);
    free(list);
}

map_t *map_create(uint width, uint height)
{
    map_t *map = calloc(1, sizeof(map_t));

    if (!map)
        return NULL;
    map->width = width;
    map->height = height;
    map->tiles = olist_create();
    map->tiles->destructor = &map_tile_destructor;
    for (uint y = 0; y < height; y++)
        for (uint x = 0; x < width; x++)
            olist_add_node(map->tiles, tile_create(x, y));
    return map;
}
