/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** destroy_socket
*/

#include <stdlib.h>
#include <unistd.h>
#include "osocket.h"

void odestroy_socket(socket_t *socket)
{
    if (!socket)
        return;
    close(socket->fd);
    free(socket);
}
