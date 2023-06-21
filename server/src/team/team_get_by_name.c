/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** team_get_by_name
*/

#include <string.h>
#include "server.h"

team_t *get_team_by_name(server_t *server, char *name)
{
    team_t *team = NULL;

    OLIST_FOREACH(server->teams, node) {
        team = (team_t *)node->data;
        if (strcmp(team->name, name) == 0)
            return team;
    }
    return NULL;
}
