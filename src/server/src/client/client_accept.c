/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_accept
*/

#include "olog.h"
#include "server.h"
#include "client.h"

static client_t *build_client(socket_t *socket)
{
    client_t *client = client_create();

    if (!client)
        return NULL;
    client->socket = socket;
    return client;
}

static int add_client(server_t *server, socket_t *socket)
{
    client_t *client = build_client(socket);

    if (!client) {
        odestroy_socket(socket);
        return EXIT_FAILTEK;
    }
    olist_add_node(server->clients, client);
    OLOG_DEBUG("New client connected: %s:%d id#%ld fd#%d",
    inet_ntoa(socket->addr.sin_addr), ntohs(socket->addr.sin_port), client->id,
    client->socket->fd);
    dprintf(client->socket->fd, "WELCOME\n");
    return 0;
}

int client_accept(server_t *server)
{
    socklen_t addr_len = sizeof(struct sockaddr_in);
    socket_t *socket = ocreate_empty_socket();

    if (!socket)
        return EXIT_FAILTEK;
    if (FD_ISSET(server->socket->fd, &server->select->readfds)) {
        socket->fd = accept(server->socket->fd,
        (struct sockaddr *)&socket->addr, &addr_len);
        if (socket->fd == -1) {
            odestroy_socket(socket);
            return EXIT_FAILTEK;
        }
        return add_client(server, socket);
    }
    return 0;
}
