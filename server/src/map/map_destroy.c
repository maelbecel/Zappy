/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map_destroy
*/

#include <stdlib.h>
#include "map.h"

void map_destroy(map_t *map)
{
    if (!map)
        return;
    if (map->tiles)
        olist_destroy(map->tiles);
    free(map);
}
