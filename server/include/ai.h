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
    NORTH = 1,
    EAST = 2,
    SOUTH = 3,
    WEST = 4
} orientation_t;

typedef enum {
    N = 1,
    NW = 2,
    W = 3,
    SW = 4,
    S = 5,
    SE = 6,
    E = 7,
    NE = 8
} rotation_orientation_t;

typedef struct ai_s {
    ulong id;
    uint level;
    int time_before_death;
    int x;
    int y;
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

/**
 * @brief Function call when a player die
 * Send a message to the graphic client
 *
 * @param client
 * @param server
 */
void ai_dead(client_t *client, server_t *server, bool disconnect);

/**
 * @brief Get direction from orientation
 *
 * @param ai
 * @param orientation
 * @return int
 */
int ai_get_direction_from_orientation(ai_t *ai, orientation_t orientation);

#endif
