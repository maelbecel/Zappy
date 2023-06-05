/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** bct
*/

#include <stdlib.h>
#include "command.h"
#include "utils.h"

static int do_bct(client_t *client, server_t *server, char **args)
{
    int x = atoi(args[1]);
    int y = atoi(args[2]);
    tile_t *tile = NULL;

    if (x < 0 || x >= (int)server->map->width || y < 0
    || y >= (int)server->map->height) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    tile = map_get_tile(server->map, x, y);
    if (!tile) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    dprintf(client->socket->fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        tile->inventory->food, tile->inventory->linemate,
        tile->inventory->deraumere, tile->inventory->sibur,
        tile->inventory->mendiane, tile->inventory->phiras,
        tile->inventory->thystame);
    return 0;
}

int bct(client_t *client, server_t *server, char **args)
{
    if (array_size(args) != 3) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    return do_bct(client, server, args);
}
