/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** action_create
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

action_t *action_create(char *name, server_t *server, client_t *client,
ulong duration)
{
    action_t *action = calloc(1, sizeof(action_t));

    if (!action)
        return NULL;
    action->name = strdup(name);
    action->duration = duration;
    action->data = calloc(3, sizeof(void *));
    if (!action->data)
        return NULL;
    action->data[0] = client;
    action->data[1] = server;
    return action;
}
