/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_options
*/

#include <getopt.h>
#include <stdio.h>
#include "options.h"

static const char *short_options = "p:x:y:n:c:f:";

static const struct option long_options[] = {
    {"port", required_argument, 0, 'p'},
    {"width", required_argument, 0, 'x'},
    {"height", required_argument, 0, 'y'},
    {"teams", required_argument, 0, 'n'},
    {"clients-nb", required_argument, 0, 'c'},
    {"freq", required_argument, 0, 'f'},
    {0, 0, 0, 0}
};

static const options_getter_t options_getter[] = {
    {'p', get_port},
    {'x', get_width},
    {'y', get_height},
    {'c', get_clients_nb},
    {'f', get_freq},
    {0, 0}
};

void flag_error(int flag, char *message)
{
    fprintf(stderr, "-%c %s\n", flag, message);
}

static int fill_options(options_t *options, int flag, int argc, char **argv)
{
    for (uint i = 0; options_getter[i].flag; i++) {
        if (options_getter[i].flag == flag)
            return options_getter[i].func(options, optarg);
    }
    if (flag == 'n')
        return get_teams_names(options, argc, argv);
    flag_error(flag, "invalid option");
    return 0;
}

options_t *get_options(int ac, char **av)
{
    options_t *options = init_options();
    int flag = 0;

    if (!options)
        return NULL;
    while ((flag = getopt_long(ac, av, short_options, long_options, 0)) != -1) {
        if (!fill_options(options, flag, ac, av)) {
            del_options(options);
            return NULL;
        }
    }
    return options;
}
