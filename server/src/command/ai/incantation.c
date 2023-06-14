/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** incantation
*/

#include "command.h"
#include "wbuffer.h"

static const incantation_resources_t INCNEED[] = {
    {1, 1, 1, 0, 0, 0, 0, 0},
    {2, 2, 1, 1, 1, 0, 0, 0},
    {3, 2, 2, 0, 1, 0, 2, 0},
    {4, 4, 1, 1, 2, 0, 1, 0},
    {5, 4, 1, 2, 1, 3, 0, 0},
    {6, 6, 1, 2, 3, 0, 1, 0},
    {7, 6, 2, 2, 2, 2, 2, 1}
};

static bool can_do_incantation(client_t *client, server_t *server)
{
    ai_t *ai = client->data;
    tile_t *tile = NULL;
    olist_t *players = NULL;

    if (!ai || ai->level > 7)
        return false;
    tile = map_get_tile(server->map, ai->x, ai->y);
    if (!tile)
        return false;
    if (tile->inventory->items[LINEMATE] < INCNEED[ai->level].linemate ||
    tile->inventory->items[DERAUMERE] < INCNEED[ai->level].deraumere ||
    tile->inventory->items[SIBUR] < INCNEED[ai->level].sibur ||
    tile->inventory->items[MENDIANE] < INCNEED[ai->level].mendiane ||
    tile->inventory->items[PHIRAS] < INCNEED[ai->level].phiras ||
    tile->inventory->items[THYSTAME] < INCNEED[ai->level].thystame)
        return false;
    players = tile_get_players_by_level(server, tile, ai->level);
    if (!players || players->size < INCNEED[ai->level].players_needed)
        return false;
    return true;
}

static void lock_unlock_players(olist_t *players, bool lock)
{
    client_t *client = NULL;
    ai_t *ai = NULL;

    OLIST_FOREACH(players, node) {
        client = node->data;
        if (!client || !client->data)
            continue;
        ai = client->data;
        if (!ai)
            continue;
        ai->incantation = lock;
    }
}

static void do_incantation(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    olist_t *players = action->data[2];

    if (!client || !server || !players)
        return;
    lock_unlock_players(players, false);
    if (!can_do_incantation(client, server)) {
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    OLIST_FOREACH(players, node) {
        client = node->data;
        if (!client)
            continue;
        ((ai_t *)client->data)->level++;
        wbuffer_add_message(client, "Current level: %d\n",
        ((ai_t *)client->data)->level);
    }
}

int incantation(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = NULL;
    ai_t *ai = NULL;
    tile_t *tile = NULL;

    if (!can_do_incantation(client, server)) {
        wbuffer_add_msg(client, "ko\n");
        return 0;
    }
    ai = client->data;
    if (!ai)
        return 0;
    tile = map_get_tile(server->map, ai->x, ai->y);
    if (!tile)
        return 0;
    action = action_create("Incantation", server, client, 300);
    action->callback = &do_incantation;
    action->data[2] = tile_get_players_by_level(server, tile, ai->level);
    lock_unlock_players((olist_t *)action->data[2], true);
    notif_ai((olist_t *)action->data[2], "Elevation underway\n");
    return 0;
}
