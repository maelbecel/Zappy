/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_destroy
*/

#include <stdlib.h>
#include "olog.h"
#include "server.h"

/**
 * The function destroys a client and frees its associated memory.
 *
 * @param client A pointer to a client_t struct, which represents
 * a client in a client-server communication system.
 *
 * @return If the `client` pointer is `NULL`, the function returns without
 * doing anything.
 */
void client_destroy(client_t *client)
{
    if (!client)
        return;
    if (client->waiting_orders)
        olist_destroy(client->waiting_orders);
    if (client->current_action)
        action_destroy(client->current_action);
    if (client->wbuffer)
        olist_destroy(client->wbuffer);
    if (client->buffer)
        free(client->buffer);
    odestroy_socket(client->socket);
    free(client);
}
