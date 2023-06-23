/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** client_accept
*/

#include "olog.h"
#include "server.h"
#include "client.h"
#include "wbuffer.h"

/**
 * The function builds a client object with a given socket.
 *
 * @param socket The parameter `socket` is a pointer to a
 * `socket_t` structure, which likely contains information
 * about a network socket such as its file descriptor, address,
 * and port number. This function uses this parameter to create
 * a new `client_t` structure and assign the `socket` parameter
 *
 * @return The function `build_client` returns a pointer to a `client_t`
 * struct. If the `client_create` function fails to allocate memory for the
 * struct, the function returns `NULL`.
 */
static client_t *build_client(int socket)
{
    client_t *client = client_create();

    if (!client)
        return NULL;
    client->socket = ocreate_socket_with_fd(socket);
    return client;
}

/**
 * The function adds a new client to the server and sends a
 * welcome message to the client.
 *
 * @param server A pointer to a server_t struct, which contains information
 * about the server.
 * @param socket A pointer to a socket_t structure representing the client's
 * socket connection to the server.
 *
 * @return an integer value. If the client is successfully added, it
 * returns 0. If there is an error in building the client, it returns
 * EXIT_FAILTEK (which is likely a typo and should be EXIT_FAILURE).
 */
static int add_client(server_t *server, int socket)
{
    client_t *client = build_client(socket);

    if (!client) {
        return EXIT_FAILTEK;
    }
    olist_add_node(server->clients, client);
    wbuffer_add_msg(client, "WELCOME\n");
    return 0;
}

/**
 * The function accepts a client connection to a server and adds
 * it to the list of clients.
 *
 * @param server a pointer to a server_t struct, which contains information
 * about the server such as its socket and a set of file descriptors for
 * select() to monitor.
 *
 * @return an integer value. If the socket creation or the accept call fails,
 * it returns EXIT_FAILTEK (which is likely a typo and should be
 * EXIT_FAILURE). If a client is successfully added to the server, it returns
 * a non-zero value (which could be the client's socket file descriptor or any
 * other value indicating success). If no client is accepted, it returns 0.
 */
int client_accept(server_t *server)
{
    socklen_t addr_len = sizeof(struct sockaddr_in);
    struct sockaddr_in addr;
    int fd = 0;

    if (FD_ISSET(server->socket->fd, &server->select->readfds)) {
        fd = accept(server->socket->fd, (struct sockaddr *)&addr, &addr_len);
        OLOG_DEBUG("New client connected: %s:%d fd#%d",
        inet_ntoa(addr.sin_addr), ntohs(addr.sin_port), fd);
        if (fd == -1)
            return EXIT_FAILTEK;
        return add_client(server, fd);
    }
    return 0;
}
