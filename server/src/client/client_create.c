/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_create
*/

#include <stdlib.h>
#include "client.h"
#include "utils.h"

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
    client->actions_queue = NULL;
    client->current_action = NULL;
    return client;
}
