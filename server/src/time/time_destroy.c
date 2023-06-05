/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** time_destroy
*/

#include <stdlib.h>
#include "server.h"

void time_destroy(time_manager_t *time)
{
    if (!time)
        return;
    free(time);
}
