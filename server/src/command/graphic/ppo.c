/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ppo
*/

#include <stdlib.h>
#include "command.h"
#include "ai.h"
#include "utils.h"

static int do_ppo(client_t *client, client_t *graphic)
{
    ai_t *ai = client->data;

    if (!ai) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    dprintf(graphic->socket->fd, "ppo %ld %d %d %d\n", client->id, ai->x, ai->y,
    ai->orientation);
    return 0;
}

int ppo(client_t *client, server_t *server, char **args)
{
    client_t *target = NULL;

    if (array_size(args) != 2 || args[1][0] != '#') {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    args[1]++;
    target = client_get_by_id(server, atoi(args[1]));
    args[1]--;
    if (!target) {
        dprintf(client->socket->fd, "sbp\n");
        return 0;
    }
    return do_ppo(target, client);
}
