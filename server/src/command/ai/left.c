/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "command.h"

static void action_left(action_t *action)
{
    client_t *client = action->data[0];
    ai_t *ai = client->data;

    if (!ai || !action->data[1] || !client) {
        OLOG_FATAL("Forward action: missing data for id#%ld fd#%d\n",
        client->id, client->socket->fd);
        dprintf(client->socket->fd, "ko\n");
        return;
    }
    switch (ai->orientation) {
        case NORTH: ai->orientation = WEST;  break;
        case SOUTH: ai->orientation = EAST;  break;
        case EAST:  ai->orientation = NORTH; break;
        case WEST:  ai->orientation = SOUTH; break;
    }
    notif_graphic(client, action->data[1], &do_ppo);
    dprintf(client->socket->fd, "ok\n");
}

int left(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Left", server, client, 7);

    if (!action)
        return 84;
    action->callback = &action_left;
    client->current_action = action;
    return 0;
}
