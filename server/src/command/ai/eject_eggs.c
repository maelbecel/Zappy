/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** eject_eggs
*/

#include "command.h"

static void notif_all_graphics(server_t *server, ulong egg_id)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client || client->type != GRAPHIC)
            continue;
        edi(egg_id, client);
    }
}

void eject_all_eggs(server_t *server, tile_t *tile)
{
    egg_t *egg = NULL;
    team_t *team = NULL;

    OLIST_FOREACH(server->eggs, node) {
        egg = node->data;
        if (!egg)
            continue;
        if (egg->x != tile->x && egg->y != tile->y)
            continue;
        team = team_get_by_id(server, egg->team_id);
        if (!team)
            continue;
        team->eggs_size--;
        notif_all_graphics(server, egg->id);
        olist_remove_node(server->eggs, olist_index_of(server->eggs,
        node->data));
    }
}
