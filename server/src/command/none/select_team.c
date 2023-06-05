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
#include "command.h"
#include "ai.h"

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

static void send_infos(client_t *client, team_t *team, server_t *server)
{
    dprintf(client->socket->fd, "%d\n",
    server->max_team_size - team->team_size);
    dprintf(client->socket->fd, "%d %d\n", server->map->width,
    server->map->height);
}

static int update_team_for_client(client_t *client, team_t *team,
server_t *server)
{
    client->type = AI;
    send_infos(client, team, server);
    if (team->team_size >= server->max_team_size) {
        OLOG_DEBUG("Client %d want to join a full team (%s)",
        client->socket->fd, client->buffer);
        client_disconnect(server, client);
        return 0;
    }
    client->team_id = team->id;
    team->team_size++;
    client->data = ai_create(server->map->width, server->map->height);
    olist_add_node(team->clients, client);
    return 0;
}

int select_team(client_t *client, server_t *server)
{
    team_t *team = NULL;

    if (!client->buffer)
        return 0;
    if (strcmp(client->buffer, "GRAPHIC") == 0) {
        OLOG_DEBUG("Client %d is now a graphic client", client->socket->fd);
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
    return update_team_for_client(client, team, server);
}
