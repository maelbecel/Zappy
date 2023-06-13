/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** mct
*/

#include "command.h"

int mct(client_t *client, server_t *server, UNUSED char **args)
{
    for (uint x = 0; x < (uint)server->map->width; x++) {
        for (uint y = 0; y < (uint)server->map->height; y++) {
            print_bct(client, map_get_tile(server->map, x, y), x, y);
        }
    }
    return 0;
}
