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
    if (tile->players) {
        while (tile->players->size > 0)
            olist_remove_node_wfree(tile->players, 0);
        olist_destroy(tile->players);
    }
    if (tile->inventory)
        inventory_destroy(tile->inventory);
    free(tile);
}
