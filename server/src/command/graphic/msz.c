/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** msz
*/

#include "command.h"
#include "olog.h"
#include "wbuffer.h"

int msz(client_t *client, server_t *server, UNUSED char **args)
{
    wbuffer_add_message(client, "msz %d %d\n", server->map->width,
        server->map->height);
    return 0;
}
