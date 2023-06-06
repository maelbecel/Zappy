/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** tna
*/

#include "command.h"

int tna(client_t *client, server_t *server, UNUSED char **args)
{
    team_t *team = NULL;

    OLIST_FOREACH(server->teams, node) {
        team = node->data;
        if (!team)
            continue;
        dprintf(client->socket->fd, "tna %s\n", team->name);
    }
    return 0;
}