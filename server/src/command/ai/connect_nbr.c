/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** connect_nbr
*/

#include "command.h"
#include "wbuffer.h"

int connect_nbr(client_t *client, server_t *server, UNUSED char **args)
{
    team_t *team = team_get_by_id(server, client->team_id);
    int nb = 0;

    if (!team)
        return 0;
    nb = server->max_team_size - team->team_size;
    wbuffer_add_message(client, "%d\n", nb);
    return 0;
}
