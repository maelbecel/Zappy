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

/**
 * @brief Create a ai object
 *
 * @param xmax Max size of the map
 * @param ymax Max size of the map
 * @return ai_t* The ai object
 */
ai_t *ai_create(uint xmax, uint ymax);

/**
 * @brief Destroy a ai object
 * Also destroy the inventory
 * @param ai
 */
void ai_destroy(ai_t *ai);

#endif
