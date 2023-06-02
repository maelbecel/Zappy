/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** get_port
*/

#include <stdlib.h>
#include "options.h"

int get_port(options_t *options, char *arg)
{
    int port = atoi(arg);

    if (port < 1024 || port > 65535) {
        flag_error('p', "option only accepts integer values between 1024 and 65535");
        return 0;
    }
    options->port = port;
    return 1;
}
