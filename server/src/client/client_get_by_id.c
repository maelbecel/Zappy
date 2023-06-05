/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_get_by_id
*/

#include "server.h"
#include "client.h"

client_t *client_get_by_id(server_t *server, ulong id)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client)
            continue;
        if (client->id == id)
            return client;
    }
    return NULL;
}
