/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** map_spawn_items
*/

#include <stdlib.h>
#include "server.h"
#include "command.h"

static tile_t *get_random_tile(server_t *server)
{
    int x = rand() % server->map->width;
    int y = rand() % server->map->height;

    return map_get_tile(server->map, x, y);
}

static uint get_spawn_quantity(server_t *server, item_t item)
{
    return (server->map->width * server->map->height * spawn_rate[item]);
}

static void put_item(server_t *server, int i)
{
    tile_t *tile = get_random_tile(server);
    if (!tile)
        return;
    tile->inventory->items[i]++;
}

static void spawn_items(server_t *server)
{
    for (int i = 0; i < MAX_INVENTORY; i++) {
        for (uint j = 0; j < get_spawn_quantity(server, i); j++) {
            put_item(server, i);
        }
    }
}

void map_spawn_items(server_t *server, bool checkTime)
{
    uint tickDiff = 0;
    uint n = 0;

    if (checkTime) {
        tickDiff = server->time->tick - server->time->spawnItemLastTick;
        if (tickDiff == 0)
            return;
        if (tickDiff < 20)
            return;
        n = (tickDiff / 20);
    } else
        n = 1;
    n = (n > 10) ? 10 : n;
    for (uint i = 0; i < n; i++)
        spawn_items(server);
    server->time->spawnItemLastTick = server->time->tick;
}
