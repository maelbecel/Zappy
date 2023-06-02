/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_teams_names
*/

#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "options.h"

int get_teams_names(options_t *options, int argc, char **argv)
{
    if (options->teams_name) {
        for (uint i = 0; options->teams_name[i]; i++)
            free(options->teams_name[i]);
        free(options->teams_name);
    }
    options->teams_name = calloc(sizeof(char *), 1);
    optind--;
    for (uint i = 0; optind < argc && *argv[optind] != '-'; optind++, i++) {
        options->teams_name = realloc(options->teams_name, sizeof(char *) * (i + 2));
        options->teams_name[i] = strdup(argv[optind]);
        options->teams_name[i + 1] = NULL;
    }
    return 1;
}
