/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "command.h"
#include "wbuffer.h"

static void action_right(action_t *action)
{
    client_t *client = action->data[0];
    ai_t *ai = client->data;

    if (!ai || !action->data[1] || !client) {
        OLOG_FATAL("Right action: missing data for id#%ld fd#%d\n",
        client->id, client->socket->fd);
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    switch (ai->orientation) {
        case NORTH: ai->orientation = EAST;  break;
        case SOUTH: ai->orientation = WEST;  break;
        case EAST:  ai->orientation = SOUTH; break;
        case WEST:  ai->orientation = NORTH; break;
    }
    notif_graphic(client, action->data[1], &do_ppo);
    wbuffer_add_msg(client, "ok\n");
}

int right(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Right", server, client, 7);

    if (!action)
        return 84;
    action->callback = &action_right;
    action_set_to_client(server, client, action);
    return 0;
}
