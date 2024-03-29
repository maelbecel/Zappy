/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pgt
*/

#include "command.h"
#include "wbuffer.h"

int pgt(server_t *server, ulong client_id, item_t item)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client)
            return EXIT_FAILTEK;
        if (client->type == GRAPHIC)
            wbuffer_add_message(client, "pgt %ld %d\n", client_id, item);
    }
    return 0;
}
