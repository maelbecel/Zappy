/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** egg_is_egg_in_team
*/

#include "server.h"

bool egg_is_egg_in_team(ulong team_id, server_t *server)
{
    egg_t *egg = NULL;

    OLIST_FOREACH(server->eggs, node) {
        egg = node->data;
        if (!egg)
            continue;
        if (egg->team_id == team_id)
            return true;
    }
    return false;
}
