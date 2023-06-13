/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pfk
*/

#include "command.h"
#include "wbuffer.h"

int pfk(client_t *client, client_t *graphic)
{
    if (!client || !graphic)
        return 84;
    wbuffer_add_message(graphic, "pfk %ld\n", client->id);
    return 0;
}
