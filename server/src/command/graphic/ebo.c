/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ebo
*/

#include "wbuffer.h"
#include "command.h"

int ebo(ulong egg_id, client_t *graphic)
{
    wbuffer_add_message(graphic, "ebo %ld\n", egg_id);
    return 0;
}
