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
        return (RORIENT == 1) ? 8 : (RORIENT == 2) ? 2 : (RORIENT == 3) ? 4 : 6;
    if (x > 0 && y < 0)
        return (RORIENT == 1) ? 6 : (RORIENT == 2) ? 8 : (RORIENT == 3) ? 2 : 4;
    if (x < 0 && y > 0)
        return (RORIENT == 1) ? 2 : (RORIENT == 2) ? 4 : (RORIENT == 3) ? 6 : 8;
    if (x < 0 && y < 0)
        return (RORIENT == 1) ? 4 : (RORIENT == 2) ? 6 : (RORIENT == 3) ? 8 : 2;
    if (x > 0 && y == 0)
        return (RORIENT == 1) ? 7 : (RORIENT == 2) ? 1 : (RORIENT == 3) ? 3 : 5;
    if (x < 0 && y == 0)
        return (RORIENT == 1) ? 3 : (RORIENT == 2) ? 5 : (RORIENT == 3) ? 7 : 1;
    if (x == 0 && y > 0)
        return (RORIENT == 1) ? 5 : (RORIENT == 2) ? 7 : (RORIENT == 3) ? 1 : 3;
    if (x == 0 && y < 0)
        return (RORIENT == 1) ? 1 : (RORIENT == 2) ? 3 : (RORIENT == 3) ? 5 : 7;
    return 0;
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
            wbuffer_add_message(target, "message %d, %s\n",
            get_direction(ai, (ai_t *)client->data), msg);
        } else if (target->type == GRAPHIC)
            wbuffer_add_message(target, "pbc %d %s\n", client->id, msg);
    }
    wbuffer_add_msg(client, "ok\n");
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
