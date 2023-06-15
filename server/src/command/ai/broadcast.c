/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** broadcast
*/

#include "command.h"
#include "wbuffer.h"
#include "utils.h"

static int get_direction(ai_t *emitter, ai_t *receiver)
{
    int x = receiver->x - emitter->x;
    int y = receiver->y - emitter->y;

    if (x > 0 && y > 0)
        return 8; // upper-right
    if (x > 0 && y < 0)
        return 6; // lower-right
    if (x < 0 && y > 0)
        return 2; // upper-left
    if (x < 0 && y < 0)
        return 4; // lower-left
    if (x > 0 && y == 0)
        return 7; // right
    if (x < 0 && y == 0)
        return 3; // left
    if (x == 0 && y > 0)
        return 1; // up
    if (x == 0 && y < 0)
        return 5; // down
    return 0; // same position
}

static void do_broadcast(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    char *msg = action->data[2];
    client_t *target = NULL;
    ai_t *ai = NULL;

    if (!client || !server || !msg)
        return;
    OLIST_FOREACH(server->clients, node) {
        target = node->data;
        if (!target)
            continue;
        if (target->type == AI && target != client) {
            ai = target->data;
            wbuffer_add_message(target, "message %d, %s\n", get_direction((ai_t *)client->data, ai), msg);
        } else if (target->type == GRAPHIC) {
            wbuffer_add_message(target, "pbc %d %s\n", client->id, msg);
        }
    }
}

int broadcast(client_t *client, server_t *server, char **args)
{
    action_t *action = NULL;

    if (array_size(args) < 2) {
        wbuffer_add_msg(client, "ko\n");
        return EXIT_SUCCESS;
    }
    action = action_create("Broadcast", server, client, 7);
    if (!action)
        return EXIT_FAILTEK;
    action->callback = &do_broadcast;
    action->data[2] = stringbuilder(args, 1);
    client->current_action = action;
    return 0;
}
