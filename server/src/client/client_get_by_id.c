/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_get_by_id
*/

#include "server.h"
#include "client.h"

/**
 * The function searches for a client in a server's list of clients by their ID
 * and returns the client if found, otherwise returns NULL.
 *
 * @param server a pointer to a server_t struct, which likely contains
 * information about the server and its clients.
 * @param id The ID of the client that we want to retrieve from the server.
 *
 * @return The function `client_get_by_id` returns a pointer to a `client_t`
 * structure that matches the given `id` parameter. If no matching client is
 * found, it returns a `NULL` pointer.
 */
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
