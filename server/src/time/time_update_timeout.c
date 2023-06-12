/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** time_update_timeout
*/

#include "olog.h"
#include "server.h"

void time_update_timeout(server_t *server, double action_time)
{
    struct timeval action_timeout;

    action_timeout.tv_sec = (int)action_time;
    action_timeout.tv_usec = (action_time - action_timeout.tv_sec) * 1000000;
    if (action_timeout.tv_sec < server->time->timeout.tv_sec ||
        (action_timeout.tv_sec == server->time->timeout.tv_sec &&
        action_timeout.tv_usec < server->time->timeout.tv_usec)) {
        server->time->timeout.tv_sec = action_timeout.tv_sec;
        server->time->timeout.tv_usec = action_timeout.tv_usec;
    }
}
