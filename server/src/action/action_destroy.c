/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** action_destroy
*/

#include <stdlib.h>
#include "server.h"

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
