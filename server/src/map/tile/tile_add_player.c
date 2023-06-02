/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tile_add_player
*/

#include "map.h"

void tile_add_player(tile_t *tile, client_t *player)
{
    OLIST_FOREACH(tile->players, node) {
        client_t *tmp = node->data;
        if (tmp->id == player->id)
            return;
    }
    olist_add_node(tile->players, player);
}
