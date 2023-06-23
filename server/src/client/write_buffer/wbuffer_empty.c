/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** wbuffer_empty
*/

#include <stdlib.h>
#include "wbuffer.h"

static char *print_with_other_msg(char *msg, char *tmp)
{
    char *tmp2 = NULL;

    asprintf(&tmp2, "%s%s", msg, tmp);
    free(msg);
    return tmp2;
}

char *wbuffer_empty(client_t *client)
{
    char *msg = NULL;
    char *tmp = NULL;

    if (!client || !client->wbuffer)
        return NULL;
    OLIST_FOREACH(client->wbuffer, node) {
        tmp = (char *)node->data;
        if (!tmp)
            continue;
        if (!msg)
            asprintf(&msg, "%s", tmp);
        else
            msg = print_with_other_msg(msg, tmp);
        free(tmp);
    }
    olist_clear_wdfree(client->wbuffer);
    if (!msg)
        return NULL;
    return msg;
}
