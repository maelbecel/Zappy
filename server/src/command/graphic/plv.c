/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** plv
*/

#include <stdlib.h>
#include "utils.h"
#include "command.h"
#include "wbuffer.h"

int do_plv(client_t *client, client_t *graphic)
{
    ai_t *ai = client->data;

    if (!ai) {
        wbuffer_add_msg(client, "sbp\n");
        return 0;
    }
    wbuffer_add_message(graphic, "plv %ld %d\n", client->id, ai->level);
    return 0;
}

int plv(client_t *client, server_t *server, char **args)
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
    return do_plv(target, client);
}
