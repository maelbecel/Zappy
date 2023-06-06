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
    print_bct(client, tile, x, y);
    return 0;
}

void print_bct(client_t *client, tile_t *tile, int x, int y)
{
    if (!tile || !client)
        return;
    dprintf(client->socket->fd, "bct %d %d %d %d %d %d %d %d %d\n", x, y,
        tile->inventory->items[0], tile->inventory->items[1],
        tile->inventory->items[2], tile->inventory->items[3],
        tile->inventory->items[4], tile->inventory->items[5],
        tile->inventory->items[6]);
}

int bct(client_t *client, server_t *server, char **args)
{
    if (array_size(args) != 3) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    return do_bct(client, server, args);
}
