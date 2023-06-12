/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** action_set_to_client
*/

#include "olog.h"
#include "server.h"

void action_set_to_client(server_t *server, client_t *client, action_t *action)
{
    struct timeval action_timeout;
    double action_time = 0.0;

    client->current_action = action;
    action_time = (double)action->duration / (double)server->time->freq;
    action_timeout.tv_sec = (int)action_time;
    action_timeout.tv_usec = (action_time - action_timeout.tv_sec) * 1000000;
    if (action_timeout.tv_sec < server->time->timeout.tv_sec ||
        (action_timeout.tv_sec == server->time->timeout.tv_sec &&
        action_timeout.tv_usec < server->time->timeout.tv_usec)) {
        server->time->timeout.tv_sec = action_timeout.tv_sec;
        server->time->timeout.tv_usec = action_timeout.tv_usec;
    }
}
