/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** command_exec
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "command.h"
#include "client.h"

int command_exec(client_t *client, server_t *server)
{
    if (client->type == NONE)
        select_team(client, server);
    if (client->buffer) {
        free(client->buffer);
        client->buffer = NULL;
    }
    return 0;
}