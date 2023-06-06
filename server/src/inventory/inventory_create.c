/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** inventory_create
*/

#include <stdlib.h>
#include "inventory.h"

const char *item_names[] = {
    "food",
    "linemate",
    "deraumere",
    "sibur",
    "mendiane",
    "phiras",
    "thystame"
};

inventory_t *inventory_create(void)
{
    inventory_t *inventory = calloc(1, sizeof(inventory_t));

    if (!inventory)
        return (NULL);
    for (uint i = 0; i < MAX_INVENTORY; i++)
        inventory->items[i] = 0;
    return (inventory);
}
