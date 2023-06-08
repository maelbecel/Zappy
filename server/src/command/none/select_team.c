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
#include "wbuffer.h"

static void send_infos(client_t *client, team_t *team, server_t *server)
{
    int team_nb = server->max_team_size - team->team_size + team->eggs_size;

    if (team_nb < 0)
        team_nb = 0;
    wbuffer_add_message(client, "%d\n",
    team_nb);
    wbuffer_add_message(client, "%d %d\n", server->map->width,
    server->map->height);

    OLIST_FOREACH(server->clients, node) {
        client_t *tmp = (client_t *)node->data;
        if (!tmp)
            continue;
        if (tmp->type == GRAPHIC) {
            pnw(tmp, client, server);
            mct(tmp, server, NULL);
        }
    }
}

static void send_infos_for_eggs(ulong egg_id, server_t *server)
{
    OLIST_FOREACH(server->clients, node) {
        client_t *tmp = (client_t *)node->data;
        if (!tmp)
            continue;
        if (tmp->type == GRAPHIC)
            ebo(egg_id, tmp);
    }
}

static void handle_egg(server_t *server, client_t *client, team_t *team)
{
    ai_t *ai = ai_create(server->map->width, server->map->height);
    egg_t *egg = NULL;

    client->team_id = team->id;
    team->team_size++;
    client->data = ai;
    if (team->eggs_size > 0) {
        team->eggs_size--;
        egg = egg_get_one_in_team(team->id, server);
        if (!egg) {
            wbuffer_add_msg(client, "ko\n");
            ai_destroy(ai);
            return;
        }
        ai->x = egg->x;
        ai->y = egg->y;
        send_infos_for_eggs(egg->id, server);
    }
    send_infos(client, team, server);
}

static int update_team_for_client(client_t *client, team_t *team,
server_t *server)
{
    if (team->team_size >= server->max_team_size && team->eggs_size == 0) {
        OLOG_DEBUG("Client %d want to join a full team (%s)",
        client->socket->fd, client->buffer);
        wbuffer_add_msg(client, "ko\n");
        return 0;
    }
    client->type = AI;
    handle_egg(server, client, team);
    tile_add_player(server->map, client);
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
        welcome(client, server);
        return 0;
    }
    team = get_team_by_name(server, client->buffer);
    if (!team) {
        client->type = NONE;
        wbuffer_add_msg(client, "ko\n");
        OLOG_INFO("Client %d want to join an unknown team (%s)",
        client->socket->fd, client->buffer);
        return 0;
    }
    return update_team_for_client(client, team, server);
}
