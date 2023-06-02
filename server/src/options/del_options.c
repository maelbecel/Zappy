/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** del_options
*/

#include <stdlib.h>
#include "options.h"

void del_options(options_t *options)
{
    if (!options)
        return;
    if (options->teams_name) {
        for (uint i = 0; options->teams_name[i]; i++)
            free(options->teams_name[i]);
        free(options->teams_name);
    }
    free(options);
}
