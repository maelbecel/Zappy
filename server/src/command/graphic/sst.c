/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sst
*/

#include <stdlib.h>
#include "command.h"
#include "utils.h"

static int do_sst(client_t *client, server_t *server, char **args)
{
    int freq = atoi(args[1]);

    if (freq < 2 || freq > 1000) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    server->time->freq = freq;
    server->time->secPerTick = 1.0 / freq;
    dprintf(client->socket->fd, "sst %d\n", freq);
    return 0;
}

int sst(client_t *client, server_t *server, char **args)
{
    if (array_size(args) != 2) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    return do_sst(client, server, args);
}
