/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai_create
*/

#include <stdlib.h>
#include "ai.h"
#include "utils.h"
#include "olog.h"

static void get_random_pos(ai_t *ai, uint xmax, uint ymax)
{
    ai->x = rand() % xmax;
    ai->y = rand() % ymax;
    OLOG_DEBUG("Generate random pos: %d %d", ai->x, ai->y);
}

ai_t *ai_create(uint xmax, uint ymax)
{
    ai_t *ai = calloc(1, sizeof(ai_t));

    if (!ai)
        return NULL;
    ai->id = generate_id();
    ai->level = 1;
    ai->time_before_death = 0;
    ai->orientation = NORTH;
    ai->inventory = inventory_create();
    ai->inventory->food = 10;
    if (!ai->inventory) {
        free(ai);
        return NULL;
    }
    ai->incantation = false;
    get_random_pos(ai, xmax, ymax);
    return ai;
}
