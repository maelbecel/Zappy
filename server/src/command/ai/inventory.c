/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#include "command.h"
#include "wbuffer.h"

static void do_inventory(action_t *action)
{
    client_t *client = action->data[0];
    ai_t *ai = NULL;

    if (!client)
        return;
    ai = client->data;
    if (!ai)
        return;
    wbuffer_add_message(client, "[ food %d, linemate %d, deraumere %d, \
sibur %d, mendiane %d, phiras %d, thystame %d ]\n", ai->inventory->items[0],
    ai->inventory->items[1], ai->inventory->items[2], ai->inventory->items[3],
    ai->inventory->items[4], ai->inventory->items[5], ai->inventory->items[6]);
}

int inventory(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Inventory", server, client, 1);

    action->callback = &do_inventory;
    action_set_to_client(server, client, action);
    return 0;
}
