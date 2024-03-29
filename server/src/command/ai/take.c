/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** take
*/

#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "utils.h"
#include "wbuffer.h"

static int take_item(client_t *client, server_t *server, char *item)
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
    notif_graphic(client, server, &do_pin);
    print_bct_for_all(server, tile, ai->x, ai->y);
    return EXIT_SUCCESS;
}

static void do_take(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    char *item = action->data[2];

    if (!client || !server) {
        OLOG_ERRORA("Fail to do take action. One of needed pointer is NULL");
        return;
    }
    if (!item) {
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    if (take_item(client, server, item) == EXIT_FAILTEK)
        wbuffer_add_msg(client, "ko\n");
    else
        wbuffer_add_msg(client, "ok\n");
    free(item);
}

int take(client_t *client, server_t *server, char **args)
{
    action_t *action = NULL;

    action = action_create("Take", server, client, 7);
    action->callback = &do_take;
    if (array_size(args) == 2)
        action->data[2] = strdup(args[1]);
    client->current_action = action;
    return 0;
}
