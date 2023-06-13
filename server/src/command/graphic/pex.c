/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pex
*/

#include "command.h"
#include "wbuffer.h"

int pex(client_t *client, client_t *graphic)
{
    wbuffer_add_message(graphic, "pex %ld\n", client->id);
    return 0;
}
