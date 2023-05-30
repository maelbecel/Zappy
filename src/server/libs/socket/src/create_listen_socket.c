/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** create_listen_socket
*/

#include <stdio.h>
#include <stdlib.h>
#include "osocket.h"

static socket_t *do_listen(socket_t *socket, int queue)
{
    if (listen(socket->fd, queue) == -1) {
        perror("listen");
        odestroy_socket(socket);
        return NULL;
    }
    return socket;
}

socket_t *ocreate_listen_socket(int port, int queue)
{
    socket_t *socket = ocreate_socket();
    socklen_t addrlen = sizeof(socket->addr);

    socket->port = port;
    socket->addr.sin_family = AF_INET;
    socket->addr.sin_port = htons(port);
    socket->addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(socket->fd, (struct sockaddr *)&socket->addr,
            addrlen) == -1) {
        perror("bind");
        odestroy_socket(socket);
        return NULL;
    }
    return do_listen(socket, queue);
}