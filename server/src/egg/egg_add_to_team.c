/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** egg_add_to_team
*/

#include "server.h"

void egg_add_to_team(server_t *server, ulong team_id)
{
    team_t *team = NULL;

    if (!server)
        return;
    team = team_get_by_id(server, team_id);
    if (!team)
        return;
    team->eggs_size++;
}
