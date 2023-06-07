/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_read
*/

#include "olog.h"
#include "server.h"
#include "client.h"
#include "command.h"
#include "utils.h"

/**
 * The function reads data from a client's socket and handles
 * disconnection if no data is received.
 *
 * @param server A pointer to a server_t struct, which likely
 * contains information about the game server such as its IP address,
 * port number, and current game state.
 * @param client The `client` parameter is a pointer to a `client_t`
 * struct, which represents a client connected to the server.
 *
 * @return The function `handle_read` returns an integer value. If the
 * `client`'s buffer is empty, the function returns `-1`. Otherwise, it
 * returns `0`.
 */
static int handle_read(server_t *server, client_t *client)
{
    read_socket(client);
    if (!client->buffer) {
        if (client->type == AI)
            ai_dead(client, server, true);
        else
            client_disconnect(server, client);
        return -1;
    }
    return 0;
}

/**
 * The function handles writing data from a client's buffer to
 * the server and executes a command.
 *
 * @param server A pointer to a server_t struct, which likely contains
 * information about the server such as its IP address, port number, and
 * any connected clients.
 * @param client The `client` parameter is a pointer to a `client_t` struct,
 * which represents a client connected to the server. It contains information
 * about the client's connection, such as its socket file descriptor and any
 * data that has been received from the client.
 *
 * @return If the `client`'s `buffer` is `NULL`, then the function returns
 * without doing anything.
 */
static void handle_write(server_t *server, client_t *client)
{
    if (!client->buffer)
        return;
    command_exec(client, server);
}

/**
 * This function handles the read and write operations for a client connected
 * to a server.
 *
 * @param server A pointer to a server_t struct, which likely contains
 * information about the server such as its socket and select file descriptor
 * sets.
 * @param client The `client` parameter is a pointer to a `client_t` struct,
 * which represents a client connected to the server. It contains information
 * about the client's socket file descriptor, address, and any data that has
 * been received from or sent to the client.
 *
 * @return The function `client_loop` returns nothing (`void`). However, if
 * `handle_read` returns `-1`, the function will immediately return without
 * executing the rest of the code.
 */
static void client_loop(server_t *server, client_t *client)
{
    if (FD_ISSET(client->socket->fd, &server->select->readfds)) {
        if (handle_read(server, client) == -1)
            return;
    }
    if (FD_ISSET(client->socket->fd, &server->select->writefds)) {
        handle_write(server, client);
    }
}

/**
 * This function reads data from all connected clients
 * of a server.
 *
 * @param server A pointer to a server_t struct, which
 * contains information about the server.
 *
 * @return an integer value of 0.
 */
int client_read(server_t *server)
{
    client_t *client = NULL;
    olist_node_t *node = server->clients->head;

    if (!node)
        return 0;
    while (server->clients->head != NULL && node != NULL) {
        client = (client_t *)node->data;
        client_loop(server, client);
        if (node)
            node = node->next;
    }
    return 0;
}
