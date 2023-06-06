/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** init_options
*/

#include <stdlib.h>
#include <string.h>
#include "options.h"

static void init_teams_name(options_t *options)
{
    options->teams_name = calloc(sizeof(char *), 5);
    options->teams_name[0] = strdup("Team1");
    options->teams_name[1] = strdup("Team2");
    options->teams_name[2] = strdup("Team3");
    options->teams_name[3] = strdup("Team4");
}

options_t *init_options(void)
{
    options_t *options = calloc(sizeof(options_t), 1);

    if (!options)
        return (NULL);
    options->port = 4242;
    options->width = 10;
    options->height = 10;
    options->teams_name = NULL;
    options->clients_nb = 2;
    options->freq = 100;
    init_teams_name(options);
    return (options);
}
