/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** egg_get_one_in_team
*/

#include "server.h"

egg_t *egg_get_one_in_team(ulong team_id, server_t *server)
{
    egg_t *egg = NULL;
    bool found = false;
    team_t *team = team_get_by_id(server, team_id);
    if (!team)
        return NULL;
    OLIST_FOREACH(server->eggs, node) {
        egg = node->data;
        if (!egg)
            continue;
        if (egg->team_id == team_id) {
            found = true;
            break;
        }
    }
    if (!egg || !found)
        return NULL;
    if (team->eggs_size > 0)
        team->eggs_size--;
    olist_remove_node_wfree(server->eggs, olist_index_of(server->eggs, egg));
    return egg;
}
