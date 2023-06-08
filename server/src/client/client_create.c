/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_create
*/

#include <stdlib.h>
#include "client.h"
#include "utils.h"

/**
 * This function creates a new client with default values
 * and returns a pointer to it.
 *
 * @return The function `client_create` returns a pointer to a newly allocated
 * `client_t` structure. If the allocation fails, it returns `NULL`.
 */
client_t *client_create(void)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client)
        return NULL;
    client->id = generate_id();
    client->socket = NULL;
    client->buffer = NULL;
    client->team_id = 0;
    client->type = NONE;
    client->data = NULL;
    client->waiting_orders = olist_create();
    client->current_action = NULL;
    return client;
}
