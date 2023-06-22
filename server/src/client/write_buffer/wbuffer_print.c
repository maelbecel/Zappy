/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** wbuffer_print
*/

#include <string.h>
#include <stdlib.h>
#include "wbuffer.h"

static void print_parts(int fd, char *buffer, uint len)
{
    uint numParts = len / MAX_READ_SIZE + 1;
    uint partSize = len / numParts;
    uint remainingSize = len % numParts;
    char *part = NULL;
    uint j = 0;

    for (uint i = 0; i < numParts; i++) {
        int currentSize = partSize;
        if (i == numParts - 1)
            currentSize += remainingSize;
        part = calloc(currentSize + 1, sizeof(char));
        strncpy(part, buffer + j, currentSize);
        dprintf(fd, "%s", part);
        j += currentSize;
        free(part);
    }
    free(buffer);
}

void wbuffer_print(int fd, char *buffer)
{
    if (!buffer)
        return;
    if (strlen(buffer) > MAX_READ_SIZE) {
        print_parts(fd, buffer, strlen(buffer));
    } else {
        dprintf(fd, "%s", buffer);
        free(buffer);
    }
}
