/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_action
*/

#include <criterion/criterion.h>
#include "server.h"

Test(test_action, test_action_1)
{
    action_t *action = action_create("test", NULL, NULL, 0);

    cr_assert_not_null(action);
    cr_assert_str_eq(action->name, "test");
    cr_assert_eq(action->duration, 0);
    cr_assert_null(action->data[0]);
    cr_assert_null(action->data[1]);
    action_destroy(action);
}

Test(test_action, test_action_2)
{
    action_destroy(NULL);
}
