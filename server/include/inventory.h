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
    THYSTAME,
    NO_ITEM
} item_t;

typedef struct inventory_s {
    uint items[MAX_INVENTORY];
} inventory_t;

extern const char *item_names[];

extern const float spawn_rate[];

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

/**
 * @brief Get an item enum from a string
 *
 * @param name
 * @return item_t
 */
item_t inventory_get_item_by_name(char *name);

#endif /* !INVENTORY_H_ */
