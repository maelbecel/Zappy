/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "client.h"
    #include "inventory.h"

typedef unsigned int uint;

typedef struct tile_s {
    uint x;
    uint y;
    uint players;
    inventory_t *inventory;
} tile_t;

typedef struct map_s {
    int width;
    int height;
    olist_t *tiles;
} map_t;

/**
 * @brief Create a map object
 * Allocate a map object and fill it with tiles
 *
 * @param width Width of the map
 * @param height Height of the map
 * @return map_t* Allocated map object
 */
map_t *map_create(uint width, uint height);

/**
 * @brief Get a tile from a map
 *
 * @param map Map object
 * @param x X position of the tile
 * @param y Y position of the tile
 * @return tile_t* Tile object
 */
tile_t *map_get_tile(map_t *map, uint x, uint y);

/**
 * @brief Destroy a map object
 * Free all the tiles and the map object
 *
 * @param map
 */
void map_destroy(map_t *map);

/**
 * @brief Create a tile object
 *
 * @param x
 * @param y
 * @return tile_t*
 */
tile_t *tile_create(uint x, uint y);

/**
 * @brief Destroy a tile object
 *
 * @param tile
 */
void tile_destroy(tile_t *tile);

/**
 * @brief Add a player to a tile
 *
 * @param map Map object
 * @param client Player to add
 */
void tile_add_player(map_t *map, client_t *client);

/**
 * @brief Remove a player from a tile
 *
 * @param tile Map object
 * @param client Player to remove
 */
void tile_remove_player(map_t *map, client_t *client);

#endif /* !MAP_H_ */
