/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_destroy
*/

#include <stdlib.h>
#include "olog.h"
#include "client.h"

void client_destroy(client_t *client)
{
    if (!client)
        return;
    if (client->waiting_orders)
        olist_destroy(client->waiting_orders);
    if (client->current_action)
        OLOG_ERRORA("Free of current action not implemented for client");
    if (client->buffer)
        free(client->buffer);
    odestroy_socket(client->socket);
    free(client);
}
