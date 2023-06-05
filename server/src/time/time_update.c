/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** time_update
*/

#include "server.h"
#include "olog.h"

void time_update(time_manager_t *time)
{
    double elapsed = 0;
    double current = 0;
    double last = 0;

    gettimeofday(&time->current, NULL);
    current = time->current.tv_sec + time->current.tv_usec / 1000000.0;
    last = time->last.tv_sec + time->last.tv_usec / 1000000.0;
    elapsed = current - last;
    if (elapsed >= time->secPerTick) {
        time->tick += elapsed / time->secPerTick;
        gettimeofday(&time->last, NULL);
    }
}
