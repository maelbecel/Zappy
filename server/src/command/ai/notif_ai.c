/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** notif_ai
*/

#include "command.h"
#include "wbuffer.h"

void notif_ai(olist_t *players, char *msg)
{
    client_t *client = NULL;

    if (!players)
        return;
    OLIST_FOREACH(players, node) {
        client = node->data;
        if (!client)
            continue;
        wbuffer_add_msg(client, msg);
    }
}
