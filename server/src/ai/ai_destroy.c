/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai_destroy
*/

#include <stdlib.h>
#include "ai.h"

void ai_destroy(ai_t *ai)
{
    if (!ai)
        return;
    inventory_destroy(ai->inventory);
    free(ai);
}
