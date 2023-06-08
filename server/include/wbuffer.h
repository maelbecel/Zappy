/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** wbuffer
*/

#ifndef WBUFFER_H_
    #define WBUFFER_H_

    #include "olog.h"
    #include <stddef.h>
    #include <stdarg.h>
    #include "client.h"

void wbuffer_add_message(client_t *client, char *fmt, ...);
void wbuffer_add_msg(client_t *client, char *msg);

char *wbuffer_empty(client_t *client);

#endif
