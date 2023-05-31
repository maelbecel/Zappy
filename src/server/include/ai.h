/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** ai
*/

#ifndef AI_H_
    #define AI_H_

    #include "server.h"
    #include "client.h"
    #include "inventory.h"

typedef enum {
    NORTH,
    EAST,
    SOUTH,
    WEST
} orientation_t;

typedef struct ai_s {
    ulong id;
    uint level;
    uint time_before_death;
    uint x;
    uint y;
    orientation_t orientation;
    inventory_t *inventory;
    bool incantation;
} ai_t;

#endif /* !AI_H_ */
