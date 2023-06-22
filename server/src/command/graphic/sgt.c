/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** sgt
*/

#include "command.h"
#include "wbuffer.h"

int sgt(client_t *client, server_t *server, UNUSED char **args)
{
    wbuffer_add_message(client, "sgt %d\n", server->time->freq);
    return 0;
}
