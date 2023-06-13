/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** sigint_handler
*/

#include <signal.h>
#include <stddef.h>
#include "server.h"
#include "olog.h"

static void signal_handler(int sig, UNUSED siginfo_t *info, void *stop)
{
    static server_t *stop_ptr = NULL;
    if (sig == -1) {
        stop_ptr = (server_t *) stop;
        return;
    }
    if (sig != SIGINT)
        return;
    OLOG_INFOA("Closing server... Bye :(");
    stop_ptr->running = false;
}

int catch_sigint(server_t *stop)
{
    struct sigaction action;

    signal_handler(-1, NULL, stop);
    action.sa_sigaction = signal_handler;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);
    if (sigaction(SIGINT, &action, NULL) == -1)
        return 84;
    return 0;
}
