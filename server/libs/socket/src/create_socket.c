/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** create_socket
*/

#include <stdlib.h>
#include <stdio.h>
#include "osocket.h"

socket_t *ocreate_socket(void)
{
    socket_t *s = calloc(sizeof(socket_t), 1);

    if (!s)
        return NULL;
    s->fd = socket(AF_INET, SOCK_STREAM, 0);
    if (s->fd == -1) {
        perror("socket");
        return NULL;
    }
    return s;
}

socket_t *ocreate_socket_with_fd(int fd)
{
    socket_t *s = calloc(sizeof(socket_t), 1);

    if (!s)
        return NULL;
    s->fd = fd;
    return s;
}

socket_t *ocreate_empty_socket(void)
{
    socket_t *s = calloc(sizeof(socket_t), 1);

    if (!s)
        return NULL;
    return s;
}
