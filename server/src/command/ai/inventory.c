/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#include "command.h"

int inventory(client_t *client, UNUSED server_t *server, UNUSED char **args)
{
    ai_t *ai = client->data;

    if (!ai) {
        dprintf(client->socket->fd, "ko\n");
        return 84;
    }
    dprintf(client->socket->fd, "[ food %d, linemate %d, deraumere %d, \
sibur %d, mendiane %d, phiras %d, thystame %d ]\n", ai->inventory->items[0],
    ai->inventory->items[1], ai->inventory->items[2], ai->inventory->items[3],
    ai->inventory->items[4], ai->inventory->items[5], ai->inventory->items[6]);
    return 0;
}
