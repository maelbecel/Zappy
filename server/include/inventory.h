/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

typedef unsigned int uint;

typedef struct inventory_s {
    uint food;
    uint linemate;
    uint deraumere;
    uint sibur;
    uint mendiane;
    uint phiras;
    uint thystame;
} inventory_t;

/**
 * @brief Create a inventory object
 * Init all values to 0
 *
 * @return inventory_t*
 */
inventory_t *inventory_create(void);

/**
 * @brief Destroy a inventory object
 *
 * @param inventory
 */
void inventory_destroy(inventory_t *inventory);

#endif /* !INVENTORY_H_ */
