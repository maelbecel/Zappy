/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pdr
*/

#include "command.h"

int pdr(server_t *server, ulong client_id, item_t item)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client)
            return EXIT_FAILTEK;
        if (client->type == GRAPHIC)
            dprintf(client->socket->fd, "pdr %ld %d\n", client_id, item);
    }
    return 0;
}
