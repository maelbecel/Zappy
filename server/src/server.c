/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** server
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "options.h"
#include "server.h"

/**
 * The function creates a server with specified options and runs a main loop.
 *
 * @param ac The "ac" parameter in this function is an integer that represents
 * the number of arguments passed to the program from the command line,
 * including the name of the program itself.
 * @param av `av` is a pointer to an array of strings, where each string
 * represents a command line argument passed to the program. The first
 * element of the array (`av[0]`) is usually the name of the program itself.
 *
 * @return either EXIT_FAILTEK or the result of the main_loop function,
 * depending on the success of the server creation and initialization.
 */
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
    srand(time(NULL));
    return main_loop(server);
}
