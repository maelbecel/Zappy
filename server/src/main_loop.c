/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** main_loop
*/

#include <stdio.h>
#include "server.h"
#include "client.h"

static void update_max_fd(server_t *server)
{
    if (!server->select)
        return;
    FD_ZERO(&server->select->readfds);
    FD_ZERO(&server->select->writefds);
    FD_SET(server->socket->fd, &server->select->readfds);

    OLIST_FOREACH(server->clients, node) {
        client_t *client = (client_t *)node->data;

        FD_SET(client->socket->fd, &server->select->readfds);
        FD_SET(client->socket->fd, &server->select->writefds);
        if ((uint) client->socket->fd > server->select->maxfd)
            server->select->maxfd = client->socket->fd;
    }
}

int main_loop(server_t *server)
{
    while (server->running) {
        update_max_fd(server);
        if (select(server->select->maxfd + 1, &server->select->readfds,
            &server->select->writefds, NULL, NULL) == -1) {
            perror("select");
            break;
        }
        if (client_accept(server) == EXIT_FAILTEK)
            return EXIT_FAILTEK;
        if (client_read(server) == EXIT_FAILTEK)
            return EXIT_FAILTEK;
    }
    return 0;
}

/*

int accept_client(server_t *server)
{
    int fd_client = 0;
    socklen_t addr_len = sizeof(struct sockaddr_in);
    struct sockaddr *client_in = (struct sockaddr *)&server->addr;

    if (FD_ISSET(server->socket, &server->rset)) {
        fd_client = accept(server->socket, client_in, &addr_len);
        if (fd_client == -1)
            return 84;
        add_node_back_cl(server, fd_client, client_in);
        send_welcome(server->users);
        printf("New client connected: %s:%d\n",
            inet_ntoa(server->users->client_in.sin_addr),
            ntohs(server->users->client_in.sin_port));
    }
    return 0;
}
static bool read_loop(server_t *server, user_t *tmp)
{
    protocol_t *protocol = NULL;
    char *buffer = NULL;

    if (FD_ISSET(tmp->clifd, &server->rset)) {
        if (!(buffer = read_input(tmp->clifd))) {
            cmd_quit(server, tmp, NULL);
            tmp = tmp->next;
            return true;
        }
    } if (FD_ISSET(tmp->clifd, &server->wset)) {
        if (buffer) {
            protocol = parse_protocol(buffer);
            teams_execve(server, tmp, protocol);
        }
    } if (buffer)
        free(buffer);
    if (protocol)
        free(protocol);
    return false;
}

void read_cmd(server_t *server, user_t *tmp)
{
    while (tmp) {
        if (tmp->clifd == -1) {
            tmp = tmp->next;
            continue;
        }
        if (read_loop(server, tmp))
            continue;
        tmp = tmp->next;
    }
}

static int get_max_fd(server_t *server)
{
    user_t *tmp = server->users;
    int max = server->socket;

    while (tmp) {
        if (tmp->clifd > max)
            max = tmp->clifd;
        tmp = tmp->next;
    }
    return max;
}

static void set_tmp(server_t *server, user_t *tmp)
{
    FD_ZERO(&server->rset);
    FD_ZERO(&server->wset);
    FD_SET(server->socket, &server->rset);
    tmp = server->users;
    while (tmp) {
        FD_SET(tmp->clifd, &server->rset);
        FD_SET(tmp->clifd, &server->wset);
        tmp = tmp->next;
    }
}

static void close_all_client(user_t *tmp)
{
    while (tmp) {
        dprintf(tmp->clifd, "Server is shutting down.\n");
        tmp = tmp->next;
    }
}

int run_server(int port)
{
    server_t *server = init_struct(port);
    user_t *tmp = NULL;

    if (!server)
        return 84;
    load_state(server);
    while (is_running(0)) {
        set_tmp(server, tmp);
        if (select(get_max_fd(server) + 1, &server->rset,
            &server->wset, NULL, NULL) == -1) {
            perror("select");
            break;
        } if (accept_client(server) == 84)
            return 84;
        tmp = server->users;
        read_cmd(server, tmp);
    } close_all_client(tmp);
    save_state(server);
    cleanup_server(server);
    return 0;
}
*/