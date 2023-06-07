/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** team_destroy
*/

#include <stdlib.h>
#include "server.h"

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
