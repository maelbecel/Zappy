/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sgt
*/

#include "command.h"

int sgt(client_t *client, server_t *server, UNUSED char **args)
{
    dprintf(client->socket->fd, "sgt %d\n", server->time->freq);
    return 0;
}
