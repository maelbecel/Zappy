/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** edi
*/

#include "command.h"
#include "wbuffer.h"

int edi(ulong egg_id, client_t *graphic)
{
    wbuffer_add_message(graphic, "edi %ld\n", egg_id);
    return 0;
}
