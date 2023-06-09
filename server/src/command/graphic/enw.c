/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** enw
*/

#include "command.h"
#include "wbuffer.h"

int enw(client_t *graphic, egg_t *egg, ulong client_id)
{
    if (!graphic || !egg)
        return 84;
    wbuffer_add_message(graphic, "enw %ld %ld %ld %ld\n", egg->id, client_id,
        egg->x, egg->y);
    return 0;
}
