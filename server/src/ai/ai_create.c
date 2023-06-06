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

/**
 * This function generates a random position within given x and y
 *  limits for an AI object.
 * 
 * @param ai The ai parameter is a pointer to a structure or object
 * of type ai_t. This structure likely contains information about an
 * AI agent in a game or simulation, such as its position, behavior,
 * and other attributes.
 * @param xmax The maximum value for the x-coordinate of the position
 * that can be generated randomly.
 * @param ymax The maximum value for the y-coordinate of the position
 * that will be generated randomly for the AI.
 */
static void get_random_pos(ai_t *ai, uint xmax, uint ymax)
{
    ai->x = rand() % xmax;
    ai->y = rand() % ymax;
    OLOG_DEBUG("Generate random pos: %d %d", ai->x, ai->y);
}

/**
 * The function creates a new AI with default values and a
 * random position within the given boundaries.
 * 
 * @param xmax The maximum x-coordinate value for the AI's
 * position on a grid or map.
 * @param ymax The ymax parameter represents the maximum y-coordinate
 *  value for the AI's position in a 2D grid.
 * 
 * @return The function `ai_create` returns a pointer to a newly created
 * `ai_t` struct. If the allocation of memory for the struct or its inventory
 * fails, it returns NULL.
 */
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
    ai->inventory->items[FOOD] = 10;
    if (!ai->inventory) {
        free(ai);
        return NULL;
    }
    ai->incantation = false;
    get_random_pos(ai, xmax, ymax);
    return ai;
}
