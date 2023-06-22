/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** incantation_utils
*/

#include "command.h"

void lock_unlock_players(olist_t *players, bool lock)
{
    client_t *client = NULL;
    ai_t *ai = NULL;

    OLIST_FOREACH(players, node) {
        client = node->data;
        if (!client || !client->data)
            continue;
        ai = client->data;
        if (!ai)
            continue;
        ai->incantation = lock;
    }
}
