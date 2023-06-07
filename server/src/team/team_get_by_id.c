/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** team_get_by_id
*/

#include "server.h"

team_t *team_get_by_id(server_t *server, ulong id)
{
    team_t *team = NULL;

    OLIST_FOREACH(server->teams, node) {
        team = node->data;
        if (team->id == id)
            return team;
    }
    return NULL;
}
