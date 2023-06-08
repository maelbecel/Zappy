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
#include "wbuffer.h"

int do_ppo(client_t *client, client_t *graphic)
{
    ai_t *ai = client->data;

    if (!ai) {
        wbuffer_add_msg(client, "sbp\n");
        return 0;
    }
    wbuffer_add_message(graphic, "ppo %ld %d %d %d\n", client->id, ai->x, ai->y,
    ai->orientation);
    return 0;
}

int ppo(client_t *client, server_t *server, char **args)
{
    client_t *target = NULL;

    if (array_size(args) != 2) {
        wbuffer_add_msg(client, "sbp\n");
        return 0;
    }
    target = client_get_by_id(server, atoi(args[1]));
    if (!target) {
        wbuffer_add_msg(client, "sbp\n");
        return 0;
    }
    return do_ppo(target, client);
}
