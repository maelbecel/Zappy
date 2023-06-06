/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

    #define MAX_INVENTORY 7

typedef unsigned int uint;

typedef enum item_s {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
} item_t;

typedef struct inventory_s {
    uint items[MAX_INVENTORY];
} inventory_t;

extern const char *item_names[];

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
