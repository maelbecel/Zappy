/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai_destroy
*/

#include <stdlib.h>
#include "ai.h"

/**
 * The function `ai_destroy` frees memory allocated for an AI's
 * inventory and the AI itself.
 * 
 * @param ai a pointer to an AI object of type ai_t.
 * 
 * @return If the `ai` parameter is `NULL`, the function returns
 * without doing anything. If `ai` is not `NULL`, the function frees
 * the memory allocated for the `ai` object and returns nothing.
 */
void ai_destroy(ai_t *ai)
{
    if (!ai)
        return;
    inventory_destroy(ai->inventory);
    free(ai);
}
