/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_width
*/

#include <stdlib.h>
#include "options.h"

int get_width(options_t *options, char *arg)
{
    int width = atoi(arg);

    if (width < 10 || width > 30) {
        flag_error('x', "option only accepts integer values between 10 and 30");
        return 0;
    }
    options->width = width;
    return 1;
}
