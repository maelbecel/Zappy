/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server_create
*/

#include <stdlib.h>
#include "server.h"

static void add_select_fds(server_t *server)
{
    server->select = calloc(1, sizeof(select_t));

    if (!server->select)
        return;
    FD_ZERO(&server->select->readfds);
    FD_ZERO(&server->select->writefds);
    FD_SET(server->socket->fd, &server->select->readfds);
    server->select->maxfd = server->socket->fd;
}

static void setup_teams(server_t *server, options_t *options)
{
    team_t *team = NULL;

    server->teams = olist_create();
    for (uint i = 0; options->teams_name[i]; i++) {
        team = team_create(options->teams_name[i]);
        olist_add_node(server->teams, team);
    }
}

server_t *server_create(options_t *options)
{
    server_t *server = calloc(1, sizeof(server_t));

    if (!server)
        return NULL;
    server->running = true;
    server->clients = olist_create();
    server->eggs = olist_create();
    server->max_team_size = options->clients_nb;
    server->map = map_create(options->width, options->height);
    if (!server->map) {
        free(server);
        return NULL;
    }
    server->socket = ocreate_listen_socket(options->port, 25);
    if (!server->socket)
        return NULL;
    add_select_fds(server);
    setup_teams(server, options);
    server->time = time_create(options->freq);
    return server;
}
