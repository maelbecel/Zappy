/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** select_team
*/

#include <string.h>
#include "olog.h"
#include "server.h"
#include "client.h"

static team_t *get_team_by_name(server_t *server, char *name)
{
    team_t *team = NULL;

    OLIST_FOREACH(server->teams, node) {
        team = (team_t *)node->data;
        if (strcmp(team->name, name) == 0)
            return team;
    }
    return NULL;
}

int select_team(client_t *client, server_t *server)
{
    team_t *team = NULL;

    if (!client->buffer)
        return 0;
    if (strcmp(client->buffer, "GRAPHIC") == 0) {
        client->type = GRAPHIC;
        return 0;
    }
    team = get_team_by_name(server, client->buffer);
    if (!team) {
        client->type = NONE;
        dprintf(client->socket->fd, "ko\n");
        OLOG_INFO("Client %d want to join an unknown team (%s)",
        client->socket->fd, client->buffer);
        return 0;
    }
    client->type = AI;
    client->team_id = team->id;
    return 0;
}
