/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** forward
*/

#include "command.h"

static void action_forward(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    ai_t *ai = client->data;

    if (!ai || !server || !client) {
        dprintf(client->socket->fd, "ko\n");
        return;
    }
    tile_remove_player(server->map, client);
    if (ai->orientation == NORTH)
        ai->y = (ai->y - 1 < 0) ? (int)server->map->height - 1 : ai->y - 1;
    if (ai->orientation == SOUTH)
        ai->y = (ai->y + 1 >= (int)server->map->height) ? 0 : ai->y + 1;
    if (ai->orientation == EAST)
        ai->x = (ai->x + 1 >= (int)server->map->width) ? 0 : ai->x + 1;
    if (ai->orientation == WEST)
        ai->x = (ai->x - 1 < 0) ? (int)server->map->width - 1 : ai->x - 1;
    notif_graphic(client, server, &do_ppo);
    dprintf(client->socket->fd, "ok\n");
    tile_add_player(server->map, client);
}

int forward(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Forward", server, client, 7);

    if (!action)
        return 84;
    action->callback = &action_forward;
    client->current_action = action;
    return 0;
}
