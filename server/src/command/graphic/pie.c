/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pie
*/

#include "command.h"
#include "wbuffer.h"

int pie(server_t *server, client_t *tmp, uint result)
{
    client_t *client = NULL;
    ai_t *ai = tmp->data;

    if (!ai)
        return 0;
    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client || client->type != GRAPHIC)
            continue;
        wbuffer_add_message(client, "pie %d %d %d\n", ai->x, ai->y, result);
    }
    return 0;
}
