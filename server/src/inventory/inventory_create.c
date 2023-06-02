/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** inventory_create
*/

#include <stdlib.h>
#include "inventory.h"

inventory_t *inventory_create(void)
{
    inventory_t *inventory = calloc(1, sizeof(inventory_t));

    if (!inventory)
        return (NULL);
    inventory->food = 0;
    inventory->linemate = 0;
    inventory->deraumere = 0;
    inventory->sibur = 0;
    inventory->mendiane = 0;
    inventory->phiras = 0;
    inventory->thystame = 0;
    return (inventory);
}
