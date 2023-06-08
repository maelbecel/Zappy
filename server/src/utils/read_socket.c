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

/**
 * The function reads data from a client's socket until a newline
 * character is encountered.
 *
 * @param client a pointer to a client_t struct, which contains
 * information about the client, including their socket file descriptor
 * and a buffer to store incoming data.
 *
 * @return The function does not explicitly return anything, but it may
 * return prematurely if there is an error reading from the client or if the
 * client disconnects.
 */
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

/**
 * The function reads data from a socket and stores it in a buffer, removing
 * the newline character at the end if present.
 *
 * @param client A pointer to a client_t struct, which likely contains
 * information about a client's connection to a server.
 *
 * @return If the allocation of memory for the client buffer fails, the
 * function returns without doing anything. Otherwise, the function reads
 * data from the client socket and stores it in the buffer. If the buffer is
 * not empty and contains a newline character at the end, the newline
 * character is replaced with a null terminator. The function does not
 * explicitly return a value, but it modifies the client buffer and may
 * return early if
 */
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
    if (!client->buffer)
        return;
    if (client->buffer[strlen(client->buffer) - 1] == '\n')
        client->buffer[strlen(client->buffer) - 1] = '\0';
}
