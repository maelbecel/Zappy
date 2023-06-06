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

static void handle_write(server_t *server, client_t *client)
{
    if (!client->buffer)
        return;
    command_exec(client, server);
}

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
