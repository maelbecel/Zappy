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
#include "olog.h"
#include "utils.h"

static const graphic_command_t graphic_commands[] = {
    {"msz", &msz},
    {"bct", &bct},
    {NULL, NULL}
};

static int command_exec_graphic(client_t *client, server_t *server, char **args)
{
    OLOG_INFO("GRAPHIC id#%ld fd#%d> %s", client->id, client->socket->fd,
    client->buffer);
    for (uint i = 0; graphic_commands[i].command; i++) {
        if (strcmp(graphic_commands[i].command, args[0]) == 0) {
            return graphic_commands[i].func(client, server, args);
        }
    }
    dprintf(client->socket->fd, "suc\n");
    return 0;
}

int command_exec(client_t *client, server_t *server)
{
    char **args = ostr_to_array(client->buffer, " ");
    if (!args) {
        OLOG_ERROR("Client id#%ld fd#%d> Failed to parse command", client->id,
        client->socket->fd);
        return EXIT_FAILTEK;
    }
    if (client->type == AI)
        command_exec_ai(client, server, args);
    else if (client->type == GRAPHIC)
        command_exec_graphic(client, server, args);
    else
        select_team(client, server);
    if (client->buffer) {
        free(client->buffer);
        client->buffer = NULL;
    }
    for (uint i = 0; args[i]; i++)
        free(args[i]);
    free(args);
    return 0;
}
