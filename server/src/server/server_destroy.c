/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** server_destroy
*/

#include <stdlib.h>
#include "server.h"

void server_destroy(server_t *server)
{
    if (!server)
        return;
    if (server->map)
        map_destroy(server->map);
    if (server->teams)
        olist_destroy(server->teams);
    if (server->clients)
        olist_destroy(server->clients);
    if (server->eggs)
        olist_destroy(server->eggs);
    if (server->time)
        time_destroy(server->time);
    if (server->socket)
        odestroy_socket(server->socket);
    if (server->select)
        free(server->select);
    free(server);
}
