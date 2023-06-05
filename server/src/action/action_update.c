/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** action_update
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "client.h"
#include "ai.h"
#include "command.h"
#include "olog.h"

static void assign_next_action(client_t *client, server_t *server)
{
    char *buffer = NULL;
    olist_node_t *node = NULL;

    if (client->current_action && client->waiting_orders->size == 0)
        return;
    node = olist_get_node(client->waiting_orders, 0);
    if (!node)
        return;
    buffer = (char *)node->data;
    if (client->buffer)
        free(client->buffer);
    client->buffer = strdup(buffer);
    olist_remove_node(client->waiting_orders, 0);
    execute_waiting_order(client, server);
}

static int update_food(client_t *client, uint tickDiff, server_t *server)
{
    ai_t *ai = client->data;

    if (!ai)
        return -1;
    ai->time_before_death -= tickDiff;
    if (ai->time_before_death <= 0) {
        if (ai->inventory->food > 0) {
            ai->inventory->food--;
            ai->time_before_death += 126;
        } else {
            ai_dead(client, server);
            return -1;
        }
    }
    return 0;
}

static void update_client(client_t *client, uint tickDiff, server_t *server)
{
    if (update_food(client, tickDiff, server) == -1)
        return;
    if (!client->current_action && client->waiting_orders->size == 0)
        return;
    if (client->current_action) {
        client->current_action->duration -= tickDiff;
        if (client->current_action->duration <= 0) {
            client->current_action->callback(client->current_action);
            client->current_action = NULL;
        }
    }
    if (!client->current_action) {
        assign_next_action(client, server);
    }
}

void action_update(server_t *server)
{
    uint tickDiff = 0;
    client_t *client = NULL;

    if (server->time->actionLastTick == 0)
        server->time->actionLastTick = server->time->tick;
    tickDiff = server->time->tick - server->time->actionLastTick;
    if (tickDiff == 0)
        return;
    OLIST_FOREACH(server->clients, node) {
        client = (client_t *)node->data;
        if (!client)
            continue;
        if (client->type != AI)
            continue;
        update_client(client, tickDiff, server);
    }
    server->time->actionLastTick = server->time->tick;
}
