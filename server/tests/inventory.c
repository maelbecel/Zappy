/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** inventory
*/

#include <criterion/criterion.h>
#include "inventory.h"

Test(test_inventory, test_inventory_1)
{
    inventory_t *inventory = inventory_create();

    cr_assert_eq(inventory->food, 0);
    cr_assert_eq(inventory->linemate, 0);
    cr_assert_eq(inventory->deraumere, 0);
    cr_assert_eq(inventory->sibur, 0);
    cr_assert_eq(inventory->mendiane, 0);
    cr_assert_eq(inventory->phiras, 0);
    cr_assert_eq(inventory->thystame, 0);
    inventory_destroy(inventory);
}

Test(test_inventory, test_inventory_2)
{
    inventory_t *inventory = inventory_create();

    inventory->food = 1;
    cr_assert_eq(inventory->food, 1);
    inventory->linemate = 1;
    cr_assert_eq(inventory->linemate, 1);
    inventory->deraumere = 1;
    cr_assert_eq(inventory->deraumere, 1);
    inventory->sibur = 1;
    cr_assert_eq(inventory->sibur, 1);
    inventory->mendiane = 1;
    cr_assert_eq(inventory->mendiane, 1);
    inventory->phiras = 1;
    cr_assert_eq(inventory->phiras, 1);
    inventory->thystame = 1;
    cr_assert_eq(inventory->thystame, 1);
    inventory_destroy(inventory);
}
