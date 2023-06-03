/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** main_loop
*/

#include <stdio.h>
#include "server.h"
#include "client.h"

static void update_max_fd(server_t *server)
{
    if (!server->select)
        return;
    FD_ZERO(&server->select->readfds);
    FD_ZERO(&server->select->writefds);
    FD_SET(server->socket->fd, &server->select->readfds);

    OLIST_FOREACH(server->clients, node) {
        client_t *client = (client_t *)node->data;

        FD_SET(client->socket->fd, &server->select->readfds);
        FD_SET(client->socket->fd, &server->select->writefds);
        if ((uint) client->socket->fd > server->select->maxfd)
            server->select->maxfd = client->socket->fd;
    }
}

int main_loop(server_t *server)
{
    while (server->running) {
        update_max_fd(server);
        if (select(server->select->maxfd + 1, &server->select->readfds,
            &server->select->writefds, NULL, NULL) == -1) {
            perror("select");
            break;
        }
        if (client_accept(server) == EXIT_FAILTEK)
            return EXIT_FAILTEK;
        if (client_read(server) == EXIT_FAILTEK)
            return EXIT_FAILTEK;
    }
    return 0;
}
