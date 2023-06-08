/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look
*/

#include "command.h"
#include "wbuffer.h"

void print_tile_content(tile_t *tile, client_t *client)
{
    if (!tile || !client)
        return;
    for (uint i = 0; i < tile->players; i++)
        wbuffer_add_msg(client, " player");
    for (uint i = 0; i < MAX_INVENTORY; i++) {
        for (uint j = 0; j < tile->inventory->items[i]; j++)
            wbuffer_add_message(client, " %s", item_names[i]);
    }
}

static void do_look(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    ai_t *ai = NULL;

    if (!server || !client)
        return;
    ai = client->data;
    if (!ai)
        return;
    wbuffer_add_msg(client, "[");
    if (ai->orientation == NORTH)
        look_north(client, server, ai);
    if (ai->orientation == SOUTH)
        look_south(client, server, ai);
    if (ai->orientation == WEST)
        look_west(client, server, ai);
    if (ai->orientation == EAST)
        look_east(client, server, ai);
    wbuffer_add_msg(client, " ]\n");
}

int look(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Look", server, client, 7);

    if (!action)
        return EXIT_FAILTEK;
    action->callback = &do_look;
    client->current_action = action;
    return EXIT_SUCCESS;
}
