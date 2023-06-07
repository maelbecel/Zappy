/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** client_disconnect
*/

#include "olog.h"
#include "server.h"
#include "client.h"

/**
 * This function handles the disconnection of a client from the server and
 * removes them from the appropriate data structures.
 *
 * @param server A pointer to a server_t struct, which contains information
 * about the server.
 * @param client A pointer to a client_t struct representing the client that
 * has disconnected.
 */
void client_disconnect(server_t *server, client_t *client)
{
    team_t *team = NULL;

    OLOG_DEBUG("Client disconnected: %s:%d id#%ld fd#%d",
    inet_ntoa(client->socket->addr.sin_addr),
    ntohs(client->socket->addr.sin_port), client->id,
    client->socket->fd);
    FD_CLR(client->socket->fd, &server->select->readfds);
    FD_CLR(client->socket->fd, &server->select->writefds);
    if (client->team_id) {
        team = team_get_by_id(server, client->team_id);
        if (team) {
            olist_remove_node_wfree(team->clients,
            olist_index_of(team->clients, client));
            team->team_size--;
        }
    }
    client_destroy(client);
    olist_remove_node_wfree(server->clients,
    olist_index_of(server->clients, client));
}
