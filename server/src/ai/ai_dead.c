/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai_dead
*/

#include "server.h"
#include "olog.h"
#include "client.h"
#include "command.h"

void ai_dead(client_t *client, server_t *server)
{
    client_t *target = NULL;

    dprintf(client->socket->fd, "dead\n");
    OLIST_FOREACH(server->clients, node) {
        target = (client_t *)node->data;
        if (target->type == GRAPHIC)
            dprintf(target->socket->fd, "pdi %ld\n", client->id);
    }
    OLOG_INFO("Client id#%ld fd#%d is dead", client->id, client->socket->fd);
    client_disconnect(server, client);
}
