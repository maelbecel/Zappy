/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** team_destroy
*/

#include <stdlib.h>
#include "server.h"

void team_list_destructor(olist_t *list)
{
    team_t *team = NULL;

    if (!list)
        return;
    OLIST_FOREACH(list, node) {
        team = (team_t *)node->data;
        if (!team)
            continue;
        team_destroy(team);
    }
    olist_clear_wdfree(list);
    free(list);
}

void team_destroy(team_t *team)
{
    if (!team)
        return;
    if (team->name)
        free(team->name);
    if (team->clients)
        olist_destroy(team->clients);
    free(team);
}
