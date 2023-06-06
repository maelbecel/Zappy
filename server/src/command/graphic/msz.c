/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** msz
*/

#include "command.h"
#include "olog.h"

int msz(client_t *client, server_t *server, UNUSED char **args)
{
    dprintf(client->socket->fd, "msz %d %d\n", server->map->width,
        server->map->height);
    return 0;
}
