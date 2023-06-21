/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** read_socket
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "client.h"
#include "olog.h"

static void do_read(client_t *client, olist_t *buffer)
{
    int read_size = 0;
    char *tmp = calloc(MAX_READ_SIZE + 1, sizeof(char));
    bool found = false;

    if (!tmp)
        return;
    while (!found) {
        read_size = read(client->socket->fd, tmp, MAX_READ_SIZE);
        if (read_size <= 0)
            break;
        if (read_size < MAX_READ_SIZE)
            found = true;
        tmp[read_size] = '\0';
        olist_add_node(buffer, strdup(tmp));
        memset(tmp, 0, MAX_READ_SIZE);
    }
    free(tmp);
}

static char *empty_buffer(olist_t *buffer)
{
    char *msg = NULL;
    char *tmp = NULL;

    if (!buffer || buffer->size == 0)
        return NULL;
    OLIST_FOREACH(buffer, node) {
        tmp = (char *)node->data;
        if (!tmp)
            continue;
        if (!msg)
            asprintf(&msg, "%s", tmp);
        else {
            asprintf(&msg, "%s%s", msg, tmp);
            free(tmp);
        }
    }
    if (!msg)
        return NULL;
    return msg;
}

void read_socket(client_t *client)
{
    olist_t *buffer = olist_create();

    if (client->buffer) {
        free(client->buffer);
        client->buffer = NULL;
    }
    do_read(client, buffer);
    client->buffer = empty_buffer(buffer);
    olist_destroy(buffer);
    if (!client->buffer)
        return;
    if (client->buffer[strlen(client->buffer) - 1] == '\n')
        client->buffer[strlen(client->buffer) - 1] = '\0';
}
