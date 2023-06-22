/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai_dead
*/

#include "server.h"
#include "olog.h"
#include "client.h"
#include "command.h"
#include "wbuffer.h"

static void fail_incantation(client_t *client)
{
    ai_t *ai = (ai_t *)client->data;
    action_t *action = NULL;
    olist_t *players = NULL;

    if (!ai)
        return;
    if (!ai->incantation || !client->current_action)
        return;
    action = (action_t *)client->current_action;
    if (!action)
        return;
    players = (olist_t *)action->data[2];
    OLIST_FOREACH(players, node) {
        client = (client_t *)node->data;
        if (!client)
            continue;
        lock_unlock_players(players, false);
    }
}

void ai_dead(client_t *client, server_t *server, bool disconnect)
{
    client_t *target = NULL;

    if (!disconnect)
        wbuffer_add_msg(client, "dead\n");
    tile_remove_player(server->map, client);
    fail_incantation(client);
    OLIST_FOREACH(server->clients, node) {
        target = (client_t *)node->data;
        if (target->type == GRAPHIC)
            wbuffer_add_message(target, "pdi %ld\n", client->id);
    }
    if (client->data)
        ai_destroy((ai_t *)client->data);
    if (!disconnect)
        OLOG_INFO("AI id#%ld fd#%d is dead", client->id,
        client->socket->fd);
    else
        OLOG_INFO("AI id#%ld fd#%d is dead (disconnected)", client->id,
        client->socket->fd);
    client_disconnect(server, client);
}
