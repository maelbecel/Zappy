/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** look_north
*/

#include "command.h"

void look_north(client_t *client, server_t *server, ai_t *ai)
{
    tile_t *tile = NULL;
    int x = 0;
    int y = 0;

    for (int i = 0; i <= (int)ai->level; i++) {
        for (int j = -i; j <= i; j++) {
            x = (ai->x + j < 0) ? server->map->width + ai->x + j : ai->x + j;
            y = (ai->y - i < 0) ? server->map->height + ai->y - i : ai->y - i;
            x = (x >= server->map->width) ? x - server->map->width : x;
            y = (y >= server->map->height) ? y - server->map->height : y;
            tile = map_get_tile(server->map, x, y);
            print_tile_content(tile, client);
            (j != i) ? dprintf(client->socket->fd, ", ") : 0;
        }
        if (i != (int)ai->level)
            dprintf(client->socket->fd, ", ");
    }
}

void look_south(client_t *client, server_t *server, ai_t *ai)
{
    tile_t *tile = NULL;
    int x = 0;
    int y = 0;

    for (int i = 0; i <= (int)ai->level; i++) {
        for (int j = i; j >= -i; j--) {
            x = (ai->x + j < 0) ? server->map->width + ai->x + j : ai->x + j;
            y = (ai->y + i >= server->map->height) ? ai->y + i -
            server->map->height : ai->y + i;
            x = (x >= server->map->width) ? x - server->map->width : x;
            y = (y >= server->map->height) ? y - server->map->height : y;
            tile = map_get_tile(server->map, x, y);
            print_tile_content(tile, client);
            (j != -i) ? dprintf(client->socket->fd, ", ") : 0;
        }
        if (i != (int)ai->level)
            dprintf(client->socket->fd, ", ");
    }
}

void look_west(client_t *client, server_t *server, ai_t *ai)
{
    tile_t *tile = NULL;
    int x = 0;
    int y = 0;

    for (int i = 0; i <= (int)ai->level; i++) {
        for (int j = i; j >= -i; j--) {
            x = (ai->x - i < 0) ? server->map->width + ai->x - i : ai->x - i;
            y = (ai->y + j < 0) ? server->map->height + ai->y + j : ai->y + j;
            x = (x >= server->map->width) ? x - server->map->width : x;
            y = (y >= server->map->height) ? y - server->map->height : y;
            tile = map_get_tile(server->map, x, y);
            print_tile_content(tile, client);
            (j != -i) ? dprintf(client->socket->fd, ", ") : 0;
        }
        if (i != (int)ai->level)
            dprintf(client->socket->fd, ", ");
    }
}

void look_east(client_t *client, server_t *server, ai_t *ai)
{
    tile_t *tile = NULL;
    int x = 0;
    int y = 0;

    for (int i = 0; i <= (int)ai->level; i++) {
        for (int j = -i; j <= i; j++) {
            x = (ai->x + i >= (int)server->map->width) ? ai->x + i -
            server->map->width : ai->x + i;
            y = (ai->y + j < 0) ? server->map->height + ai->y + j : ai->y + j;
            x = (x >= server->map->width) ? x - server->map->width : x;
            y = (y >= server->map->height) ? y - server->map->height : y;
            tile = map_get_tile(server->map, x, y);
            print_tile_content(tile, client);
            (j != i) ? dprintf(client->socket->fd, ", ") : 0;
        }
        if (i != (int)ai->level)
            dprintf(client->socket->fd, ", ");
    }
}
