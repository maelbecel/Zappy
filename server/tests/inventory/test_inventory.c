/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_inventory
*/

#include <criterion/criterion.h>
#include "inventory.h"

Test(test_inventory, test_inventory_1)
{
    inventory_t *inventory = inventory_create();

    cr_assert_not_null(inventory);
    cr_assert_eq(inventory->items[0], 0);
    cr_assert_eq(inventory->items[1], 0);
    cr_assert_eq(inventory->items[2], 0);
    cr_assert_eq(inventory->items[3], 0);
    cr_assert_eq(inventory->items[4], 0);
    cr_assert_eq(inventory->items[5], 0);
    cr_assert_eq(inventory->items[6], 0);

    inventory_destroy(inventory);
}

Test(test_inventory, test_inventory_2)
{
    inventory_destroy(NULL);
}

Test(test_inventory, test_inventory_3)
{
    item_t item = inventory_get_item_by_name("food");

    cr_assert_eq(item, FOOD);
}

Test(test_inventory, test_inventory_4)
{
    item_t item = inventory_get_item_by_name("test");

    cr_assert_eq(item, NO_ITEM);
}
