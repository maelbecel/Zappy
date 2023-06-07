/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** action_create
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"

/**
 * This function creates an action with a given name, server, client,
 * and duration.
 * 
 * @param name A string representing the name of the action.
 * @param server The server parameter is a pointer to a server_t struct,
 * which likely contains information about the server such as its IP address,
 * port number, and other relevant details. This parameter is used to
 * associate the action with a specific server.
 * @param client The client parameter is a pointer to a client_t struct,
 * which likely contains information about a client connected to the server.
 * This parameter is used to store a reference to the client in the action_t
 * struct created by the action_create function.
 * @param duration The duration parameter is of type ulong (unsigned long)
 * and represents the duration
 * of the action in some unit of time (e.g. seconds, milliseconds).
 *
 * @return The function `action_create` returns a pointer to an `action_t`
 * struct. If the allocation of
 * memory for the struct or its `data` field fails, it returns `NULL`.
 */
action_t *action_create(char *name, server_t *server, client_t *client,
ulong duration)
{
    action_t *action = calloc(1, sizeof(action_t));

    if (!action)
        return NULL;
    action->name = strdup(name);
    action->duration = duration;
    action->data = calloc(4, sizeof(void *));
    if (!action->data)
        return NULL;
    action->data[0] = client;
    action->data[1] = server;
    return action;
}
