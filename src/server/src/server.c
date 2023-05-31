/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** server
*/

#include <stdio.h>
#include "options.h"
#include "server.h"

int server(int ac, char **av)
{
    options_t *options = get_options(ac, av);
    server_t *server = NULL;

    if (!options)
        return (EXIT_FAILTEK);
    server = server_create(options);
    if (!server)
        return (EXIT_FAILTEK);
    printf("Port: %d\n", options->port);
    del_options(options);
    return main_loop(server);
}
