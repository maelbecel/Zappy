/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** incantation
*/

#include "command.h"
#include "wbuffer.h"

static const incantation_resources_t INCNEED[] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
};

bool can_do_incantation(client_t *client, server_t *server)
{
    ai_t *ai = client->data;
    tile_t *tile = NULL;
    olist_t *players = NULL;

    if (!ai || ai->level > 7)
        return false;
    tile = map_get_tile(server->map, ai->x, ai->y);
    if (!tile)
        return false;
    if (tile->inventory->items[LINEMATE] < INCNEED[ai->level - 1].linemate ||
    tile->inventory->items[DERAUMERE] < INCNEED[ai->level - 1].deraumere ||
    tile->inventory->items[SIBUR] < INCNEED[ai->level - 1].sibur ||
    tile->inventory->items[MENDIANE] < INCNEED[ai->level - 1].mendiane ||
    tile->inventory->items[PHIRAS] < INCNEED[ai->level - 1].phiras ||
    tile->inventory->items[THYSTAME] < INCNEED[ai->level - 1].thystame)
        return false;
    players = tile_get_players_by_level(server, tile, ai->level);
    if (!players || players->size < INCNEED[ai->level - 1].players_needed) {
        olist_destroy(players);
        return false;
    }
    olist_destroy(players);
    return true;
}

static void remove_resources(client_t *client, server_t *server)
{
    ai_t *ai = client->data;
    tile_t *tile = NULL;

    if (!ai)
        return;
    tile = map_get_tile(server->map, ai->x, ai->y);
    if (!tile)
        return;
    tile->inventory->items[LINEMATE] -= INCNEED[ai->level - 1].linemate;
    tile->inventory->items[DERAUMERE] -= INCNEED[ai->level - 1].deraumere;
    tile->inventory->items[SIBUR] -= INCNEED[ai->level - 1].sibur;
    tile->inventory->items[MENDIANE] -= INCNEED[ai->level - 1].mendiane;
    tile->inventory->items[PHIRAS] -= INCNEED[ai->level - 1].phiras;
    tile->inventory->items[THYSTAME] -= INCNEED[ai->level - 1].thystame;
}

static void update_players_level(olist_t *players, server_t *server)
{
    client_t *client = NULL;

    OLIST_FOREACH(players, node) {
        client = node->data;
        if (!client)
            continue;
        ((ai_t *)client->data)->level++;
        wbuffer_add_message(client, "Current level: %d\n",
        ((ai_t *)client->data)->level);
        notif_graphic(client, server, &do_plv);
    }
}

static void do_incantation(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    olist_t *players = action->data[2];
    ai_t *ai = NULL;

    if (!client || !server || !players)
        return;
    lock_unlock_players(players, false);
    ai = client->data;
    if (!ai)
        return;
    if (!can_do_incantation(client, server)) {
        notif_ai(players, "ko\n");
        pie(server, client, ai->level);
        return;
    }
    pie(server, client, ai->level + 1);
    update_players_level(players, server);
    remove_resources(client, server);
    olist_destroy(players);
}

int incantation(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = NULL;
    ai_t *ai = NULL;
    tile_t *tile = NULL;
    olist_t *players = NULL;
    bool can = (can_do_incantation(client, server)) ? true : false;

    ai = client->data;
    tile = map_get_tile(server->map, ai->x, ai->y);
    players = tile_get_players_by_level(server, tile, ai->level);
    if (can)
        notif_ai(players, "Elevation underway\n");
    else
        notif_ai(players, "ko\n");
    lock_unlock_players(players, true);
    action = action_create("Incantation", server, client, 300);
    action->data[2] = players;
    action->callback = &do_incantation;
    client->current_action = action;
    pic(server, players, ai->x, ai->y);
    return 0;
}
