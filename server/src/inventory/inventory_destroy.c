/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory_destroy
*/

#include <stdlib.h>
#include "inventory.h"

void inventory_destroy(inventory_t *inventory)
{
    if (!inventory)
        return;
    free(inventory);
}
