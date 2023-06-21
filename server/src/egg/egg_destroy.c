/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** egg_destroy
*/

#include <stdlib.h>
#include "server.h"

void egg_list_destructor(olist_t *list)
{
    egg_t *egg = NULL;

    if (!list)
        return;
    OLIST_FOREACH(list, node) {
        egg = (egg_t *)node->data;
        if (!egg)
            continue;
        egg_destroy(egg);
    }
    olist_clear_wdfree(list);
    free(list);
}

void egg_destroy(egg_t *egg)
{
    if (!egg)
        return;
    free(egg);
}
