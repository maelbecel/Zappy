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

/**
 * This function assigns the next action to a client from their waiting orders
 * list.
 *
 * @param client A pointer to a client_t struct, which likely contains
 * information about a client connected to a server.
 * @param server A pointer to a server_t struct, which likely contains
 * information about the server and its current state.
 *
 * @return If `client->current_action` is not NULL and
 * `client->waiting_orders->size` is 0, then nothing is being returned and
 * the function exits early. If `node` is not found or is NULL, then
 * nothing is being returned and the function exits early.
 */
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

/**
 * The function updates the food level of an AI client and triggers its death
 * if it runs out of food.
 *
 * @param client A pointer to a client structure, which likely contains
 * information about a player or AI in the game.
 * @param tickDiff tickDiff is the time difference between the current tick
 * and the previous tick in the game. It is used to update the time before
 * the AI dies and to check if the AI has enough food to survive.
 * @param server The server parameter is a pointer to the server structure,
 * which contains information about the game server that the client is
 * connected to. This structure may include things like the current game
 * state, player information, and other server-specific data.
 *
 * @return an integer value. If the function is successful, it returns 0.
 * If there is an error, it returns -1.
 */
static int update_food(client_t *client, uint tickDiff, server_t *server)
{
    ai_t *ai = client->data;

    if (!ai)
        return -1;
    ai->time_before_death -= tickDiff;
    if (ai->time_before_death <= 0) {
        if (ai->inventory->items[FOOD] > 0) {
            ai->inventory->items[FOOD]--;
            ai->time_before_death += 126;
        } else {
            ai_dead(client, server, false);
            return -1;
        }
    }
    return 0;
}

/**
 * This function updates a client's actions and assigns a new action
 * if the current one is completed or there are no current actions.
 *
 * @param client A pointer to a client_t struct, which represents a client in
 * the server.
 * @param tickDiff tickDiff is a variable representing the time difference
 * between the current tick and the previous tick in the game. It is used to
 * update the duration of the current action of a client and to determine when
 * to assign the next action to the client.
 * @param server A pointer to a server_t struct, which likely contains
 * information about the game server that the client is connected to.
 *
 * @return If `update_food(client, tickDiff, server)` returns -1, the function
 * will return without performing any further actions.
 */
static void update_client(client_t *client, uint tickDiff, server_t *server)
{
    ai_t *ai = client->data;

    if (update_food(client, tickDiff, server) == -1)
        return;
    if (!client->current_action && client->waiting_orders->size == 0)
        return;
    if (client->current_action) {
        client->current_action->duration -= tickDiff;
        if (client->current_action->duration <= 0) {
            client->current_action->callback(client->current_action);
            action_destroy(client->current_action);
            client->current_action = NULL;
        }
    }
    if (!ai)
        return;
    if (!client->current_action && !ai->incantation) {
        assign_next_action(client, server);
    }
}

/**
 * This function updates all AI clients in the server with the time
 * difference since the last update.
 *
 * @param server a pointer to the server structure which contains information
 * about the game server.
 *
 * @return If `tickDiff` is equal to 0, the function returns without
 * performing any further actions.
 */
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
