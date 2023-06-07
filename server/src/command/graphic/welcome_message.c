/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** welcome_message
*/

#include "command.h"

int welcome(client_t *client, server_t *server)
{
    msz(client, server, NULL);
    sgt(client, server, NULL);
    mct(client, server, NULL);
    tna(client, server, NULL);
    OLIST_FOREACH(server->clients, node) {
        client_t *target = node->data;
        if (!target)
            return 0;
        if (target->type == AI)
            pnw(client, target, server);
    }
    return 0;
}
