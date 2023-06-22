/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_except
*/

#include "command.h"
#include "ai.h"
#include "olog.h"

int client_except(server_t *server)
{
    client_t *client = NULL;
    olist_node_t *node = server->clients->head;

    if (!node)
        return 0;
    OLIST_FOREACH(server->clients, node) {
        client = (client_t *)node->data;
        if (!client)
            continue;
        if (FD_ISSET(client->socket->fd, &server->select->exceptfds)) {
            OLOG_ERROR("Client fd#%d raised an exception", client->socket->fd);
            (client->type == AI) ? ai_dead(client, server, true) :
            client_disconnect(server, client);
        }
    }
    return 0;
}
