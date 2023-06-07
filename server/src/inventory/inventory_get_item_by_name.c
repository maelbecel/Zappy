/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** inventory_get_item_by_name
*/

#include <string.h>
#include "inventory.h"

item_t inventory_get_item_by_name(char *name)
{
    for (uint i = 0; i < 7; i++) {
        if (strcmp(item_names[i], name) == 0)
            return i;
    }
    return NO_ITEM;
}
