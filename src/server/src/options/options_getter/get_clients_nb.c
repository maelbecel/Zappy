/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_clients_nb
*/

#include <stdlib.h>
#include "options.h"

int get_clients_nb(options_t *options, char *arg)
{
    int clients_nb = atoi(arg);

    if (clients_nb <= 0) {
        flag_error('c', "option only accepts integer values greater or equal to 1");
        return 0;
    }
    options->clients_nb = clients_nb;
    return 1;
}