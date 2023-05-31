/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** read_socket
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "olog.h"
#include "client.h"

static void do_read(client_t *client)
{
    int read_size = 0;

    while (strlen(client->buffer) < 1
    || client->buffer[strlen(client->buffer) - 1] != '\n') {
        read_size = read(client->socket->fd, client->buffer +
        strlen(client->buffer), MAX_READ_SIZE);
        if (read_size == 0) {
            free(client->buffer);
            client->buffer = NULL;
            return;
        }
        if (read_size == -1) {
            OLOG_ERROR("Failed to read from client #%ld", client->id);
            return;
        }
    }
}

void read_socket(client_t *client)
{
    if (client->buffer) {
        free(client->buffer);
        client->buffer = NULL;
    }
    client->buffer = calloc(MAX_READ_SIZE, sizeof(char));
    if (!client->buffer) {
        OLOG_FATALA("Failed to allocate memory for client buffer");
        return;
    }
    do_read(client);
}
