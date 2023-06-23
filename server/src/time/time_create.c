/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** time_create
*/

#include <stdlib.h>
#include "server.h"

time_manager_t *time_create(uint freq)
{
    time_manager_t *time = calloc(1, sizeof(time_manager_t));

    if (!time)
        return NULL;
    time->tick = 0;
    time->secPerTick = 1.0 / freq;
    time->currentSeason = SPRING;
    gettimeofday(&time->last, NULL);
    gettimeofday(&time->current, NULL);
    time->freq = freq;
    time->actionLastTick = 0;
    time->spawnItemLastTick = 0;
    time->seasonLastTick = 0;
    return time;
}
