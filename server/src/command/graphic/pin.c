/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** pin
*/

#include <stdlib.h>
#include "utils.h"
#include "command.h"

int do_pin(client_t *client, client_t *graphic)
{
    ai_t *ai = client->data;

    if (!ai) {
        dprintf(graphic->socket->fd, "sbp\n");
        return 0;
    }
    dprintf(graphic->socket->fd, "pin %ld %d %d %d %d %d %d %d %d %d\n",
    client->id, ai->x, ai->y, ai->inventory->items[0], ai->inventory->items[1],
    ai->inventory->items[2], ai->inventory->items[3], ai->inventory->items[4],
    ai->inventory->items[5], ai->inventory->items[6]);
    return 0;
}

int pin(client_t *client, server_t *server, char **args)
{
    client_t *target = NULL;

    if (array_size(args) != 2) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    target = client_get_by_id(server, atoi(args[1]));
    if (!target) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    return do_pin(target, client);
}
