/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** get_freq
*/

#include <stdlib.h>
#include "options.h"

int get_freq(options_t *options, char *arg)
{
    int freq = atoi(arg);

    if (freq < 2 || freq > 10000) {
        flag_error('f', "option only accepts integer values between 2 and 10000");
        return 0;
    }
    options->freq = freq;
    return 1;
}