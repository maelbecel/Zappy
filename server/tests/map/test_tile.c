/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_tile
*/

#include <criterion/criterion.h>
#include "map.h"

Test(test_tile, test_tile_1)
{
    tile_t *tile = tile_create(0, 0);

    cr_assert_not_null(tile);
    tile_destroy(tile);
}

Test(test_tile, test_tile_2)
{
    tile_destroy(NULL);
}
