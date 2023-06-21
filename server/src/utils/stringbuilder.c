/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** stringbuilder
*/

#include <stdlib.h>
#include <string.h>
#include "utils.h"

char *stringbuilder(char **str, uint start_pos)
{
    char *result = NULL;
    uint i = start_pos;
    uint j = 0;
    uint size = 0;

    for (; str[i]; i++)
        size += strlen(str[i]);
    result = calloc(sizeof(char), size + 1);
    for (i = start_pos; str[i]; i++) {
        for (uint k = 0; str[i][k]; k++, j++)
            result[j] = str[i][k];
        result[j] = ' ';
        j++;
    }
    return result;
}
