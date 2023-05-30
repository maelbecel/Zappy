/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** server
*/

#include "options.h"

int server(int ac, char **av)
{
    options_t *options = get_options(ac, av);

    if (!options)
        return (EXIT_FAILTEK);
    del_options(options);
    return (0);
}
