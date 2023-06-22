/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** tile_get_players
*/

#include "server.h"
#include "ai.h"

olist_t *tile_get_players_by_level(server_t *server, tile_t *tile, uint level)
{
    olist_t *players = olist_create();
    client_t *client = NULL;
    ai_t *ai = NULL;

    if (!players)
        return NULL;
    players->destructor = &default_destructor_no_free;
    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client || !client->data)
            continue;
        ai = client->data;
        if (ai->x == (int)tile->x && ai->y == (int)tile->y &&
        ai->level == level)
            olist_add_node(players, client);
    }
    return players;
}

olist_t *tile_get_players(server_t *server, tile_t *tile)
{
    olist_t *players = olist_create();
    client_t *client = NULL;
    ai_t *ai = NULL;

    if (!players)
        return NULL;
    players->destructor = &default_destructor_no_free;
    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client || !client->data)
            continue;
        ai = client->data;
        if (ai->x == (int)tile->x && ai->y == (int)tile->y)
            olist_add_node(players, client);
    }
    return players;
}
