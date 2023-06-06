/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_height
*/

#include <stdlib.h>
#include "options.h"

int get_height(options_t *options, char *arg)
{
    int height = atoi(arg);

    if (height < 10 || height > 30) {
        flag_error('y', "option only accepts integer values between 10 and 30");
        return 0;
    }
    options->height = height;
    return 1;
}
