/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** notif_graphic
*/

#include "command.h"

void notif_graphic(client_t *client, server_t *server,
int (*func)(client_t *client, client_t *graphic))
{
    client_t *graphic = NULL;

    OLIST_FOREACH(server->clients, node) {
        graphic = node->data;
        if (!graphic)
            continue;
        if (graphic->type == GRAPHIC)
            func(client, graphic);
        graphic = NULL;
    }
}
