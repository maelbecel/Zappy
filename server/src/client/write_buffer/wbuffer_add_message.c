/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** wbuffer_add_message
*/

#include <string.h>
#include "wbuffer.h"

void wbuffer_add_message(client_t *client, char *fmt, ...)
{
    va_list args;
    char *msg = NULL;

    va_start(args, fmt);
    vasprintf(&msg, fmt, args);
    va_end(args);
    if (!msg)
        return;
    olist_add_node(client->wbuffer, msg);
}

void wbuffer_add_msg(client_t *client, char *msg)
{
    if (!msg)
        return;
    olist_add_node(client->wbuffer, strdup(msg));
}
