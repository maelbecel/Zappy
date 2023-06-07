/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** action_destroy
*/

#include <stdlib.h>
#include "server.h"

/**
 * The function frees memory allocated for an action structure.
 *
 * @param action A pointer to an action_t struct, which contains
 * information about an action.
 *
 * @return If the `action` parameter is `NULL`, the function returns
 * immediately without doing anything. Otherwise, it frees the memory
 * allocated for the `name`, `data`, and `action` structures.
 * No value is returned explicitly.
 */
void action_destroy(action_t *action)
{
    if (!action)
        return;
    if (action->name)
        free(action->name);
    if (action->data)
        free(action->data);
    free(action);
}
