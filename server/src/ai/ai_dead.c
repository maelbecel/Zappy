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
#include "wbuffer.h"

/**
 * The function handles the death of a client in a server and notifies
 * all graphic clients of the death.
 *
 * @param client A pointer to the client that is dead or disconnected.
 * @param server A pointer to the server structure.
 * @param disconnect The "disconnect" parameter is a boolean value that
 * indicates whether the client has disconnected or not. If it is true,
 * it means that the client has disconnected, and if it is false, it
 * means that the client is still connected.
 */
void ai_dead(client_t *client, server_t *server, bool disconnect)
{
    client_t *target = NULL;

    if (!disconnect)
        wbuffer_add_msg(client, "dead\n");
    tile_remove_player(server->map, client);
    OLIST_FOREACH(server->clients, node) {
        target = (client_t *)node->data;
        if (target->type == GRAPHIC)
            wbuffer_add_message(target, "pdi %ld\n", client->id);
    }
    if (client->data)
        ai_destroy((ai_t *)client->data);
    if (!disconnect)
        OLOG_INFO("AI id#%ld fd#%d is dead", client->id,
        client->socket->fd);
    else
        OLOG_INFO("AI id#%ld fd#%d is dead (disconnected)", client->id,
        client->socket->fd);
    client_disconnect(server, client);
}
