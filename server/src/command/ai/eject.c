/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** eject
*/

#include "command.h"
#include "wbuffer.h"

static void update_pos_and_send_eject(client_t *client, ai_t *ai,
orientation_t orientation)
{
    int eject_direction = ai_get_direction_from_orientation(ai, orientation);

    if (orientation == NORTH)
        ai->y -= 1;
    if (orientation == EAST)
        ai->x += 1;
    if (orientation == SOUTH)
        ai->y += 1;
    if (orientation == WEST)
        ai->x -= 1;
    wbuffer_add_message(client, "eject: %d\n", eject_direction);
}

static void eject_all_players(olist_t *players, server_t *server,
orientation_t orientation, ulong pusher)
{
    client_t *client = NULL;
    ai_t *ai = NULL;

    OLIST_FOREACH(players, node) {
        client = node->data;
        if (!client || !client->data)
            continue;
        if (client->id == pusher)
            continue;
        ai = client->data;
        if (!ai)
            continue;
        update_pos_and_send_eject(client, ai, orientation);
        notif_graphic(client, server, do_ppo);
    }
}

static void continue_eject(client_t *client, server_t *server, ai_t *ai,
tile_t *tile)
{
    olist_t *players = NULL;

    if (tile->players == 1) {
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    players = tile_get_players(server, tile);
    if (!players) {
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    notif_graphic(client, server, &pex);
    eject_all_players(players, server, ai->orientation, client->id);
    eject_all_eggs(server, tile);
    olist_destroy(players);
    wbuffer_add_msg(client, "ok\n");
}

static void do_eject(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    tile_t *tile = NULL;
    ai_t *ai = NULL;

    if (!client || !server)
        return;
    ai = client->data;
    if (!ai) {
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    tile = map_get_tile(server->map, ai->x, ai->y);
    if (!tile) {
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    continue_eject(client, server, ai, tile);
}

int eject(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Eject", server, client, 7);

    if (!action)
        return 84;
    action->callback = &do_eject;
    client->current_action = action;
    return 0;
}
