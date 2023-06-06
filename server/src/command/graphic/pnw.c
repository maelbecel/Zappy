/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pnw
*/

#include "command.h"

int pnw(client_t *graphic, client_t *target, server_t *server)
{
    ai_t *ai = target->data;
    team_t *team = NULL;

    if (!ai)
        return 0;
    team = team_get_by_id(server, target->team_id);
    if (!team)
        return 0;
    dprintf(graphic->socket->fd, "pnw %ld %d %d %d %d %s\n",
    target->id, ai->x, ai->y, ai->orientation, ai->level, team->name);
    return 0;
}
