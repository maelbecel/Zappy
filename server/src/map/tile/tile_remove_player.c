/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tile_remove_player
*/

#include "map.h"

void tile_remove_player(tile_t *tile, client_t *player)
{
    uint index = 0;

    OLIST_FOREACH(tile->players, node) {
        client_t *tmp = node->data;
        if (tmp->id == player->id) {
            index = olist_index_of(tile->players, node->data);
            olist_remove_node_wfree(tile->players, index);
            return;
        }
    }
}
