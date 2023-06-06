/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** take
*/

#include "command.h"
#include "utils.h"

static int take_resource(client_t *client, server_t *server, char *item)
{
    ai_t *ai = client->data;
    item_t item_id = NO_ITEM;
    tile_t *tile = NULL;

    if (!ai)
        return EXIT_FAILTEK;
    item_id = inventory_get_item_by_name(item);
    if (item_id == NO_ITEM)
        return EXIT_FAILTEK;
    tile = map_get_tile(server->map, ai->x, ai->y);
    if (!tile)
        return EXIT_FAILTEK;
    if (tile->inventory->items[item_id] == 0)
        return EXIT_FAILTEK;
    tile->inventory->items[item_id]--;
    ai->inventory->items[item_id]++;
    pgt(server, client->id, item_id);
    notif_graphic(client, server, &pin);
    print_bct_for_all(server, tile, ai->x, ai->y);
    return EXIT_SUCCESS;
}

int take(client_t *client, server_t *server, char **args)
{
    if (array_size(args) != 2) {
        dprintf(client->socket->fd, "ko\n");
        return EXIT_SUCCESS;
    }
    if (take_resource(client, server, args[1]) == EXIT_FAILTEK)
        dprintf(client->socket->fd, "ko\n");
    else
        dprintf(client->socket->fd, "ok\n");
}
