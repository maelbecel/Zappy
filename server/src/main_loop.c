/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** main_loop
*/

#include <stdio.h>
#include "server.h"
#include "client.h"
#include "olog.h"

/**
 * The function updates the maximum file descriptor for the server's select
 * object based on the file descriptors of the server's socket and its
 * clients' sockets.
 *
 * @param server a pointer to a server_t struct, which contains information
 * about the server and its clients.
 *
 * @return If `server->select` is `NULL`, the function returns without doing
 * anything. Otherwise, it clears the read and write file descriptor sets
 * using `FD_ZERO`, sets the server socket file descriptor in the read file
 * descriptor set using `FD_SET`, and sets the file descriptors of all
 * connected clients in both the read and write file descriptor sets using
 * `FD_SET`. Finally, it updates the maximum file
 */
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

/**
 * This function runs a loop that updates the server and handles
 * client connections and actions.
 *
 * @param server a pointer to a server_t struct, which likely
 * contains information about the game server being run.
 *
 * @return an integer value of 0.
 */
int main_loop(server_t *server)
{
    map_spawn_items(server, false);
    while (server->running) {
        update_max_fd(server);
        if (select(server->select->maxfd + 1, &server->select->readfds,
            &server->select->writefds, NULL, (server->time->timeout.tv_sec > 0
            || server->time->timeout.tv_usec > 0) ?
            &server->time->timeout : NULL) == -1) {
            perror("select");
            break;
        }
        if (client_accept(server) == EXIT_FAILTEK)
            return EXIT_FAILTEK;
        if (client_read(server) == EXIT_FAILTEK)
            return EXIT_FAILTEK;
        time_update(server->time);
        action_update(server);
        map_spawn_items(server, true);
    }
    return 0;
}
