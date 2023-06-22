/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_ai
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(test_ai, test_ai_1)
{
    ai_t *ai = ai_create(0, 0);

    cr_assert_not_null(ai);
    cr_assert_eq(ai->x, 0);
    cr_assert_eq(ai->y, 0);
    ai_destroy(ai);
}

Test(test_ai, test_ai_2)
{
    ai_destroy(NULL);
}

Test(test_ai, test_ai_3)
{
    ai_t *ai = ai_create(0, 0);

    ai->orientation = NORTH;

    cr_assert_eq(ai_get_direction_from_orientation(ai, NORTH), S);
    cr_assert_eq(ai_get_direction_from_orientation(ai, EAST), W);
    cr_assert_eq(ai_get_direction_from_orientation(ai, WEST), E);
    cr_assert_eq(ai_get_direction_from_orientation(ai, SOUTH), N);
}

Test(test_ai, test_ai_4)
{
    ai_t *ai = ai_create(0, 0);

    ai->orientation = SOUTH;

    cr_assert_eq(ai_get_direction_from_orientation(ai, NORTH), N);
    cr_assert_eq(ai_get_direction_from_orientation(ai, EAST), E);
    cr_assert_eq(ai_get_direction_from_orientation(ai, WEST), W);
    cr_assert_eq(ai_get_direction_from_orientation(ai, SOUTH), S);
}

Test(test_ai, test_ai_5)
{
    ai_t *ai = ai_create(0, 0);

    ai->orientation = WEST;

    cr_assert_eq(ai_get_direction_from_orientation(ai, NORTH), E);
    cr_assert_eq(ai_get_direction_from_orientation(ai, EAST), N);
    cr_assert_eq(ai_get_direction_from_orientation(ai, WEST), S);
    cr_assert_eq(ai_get_direction_from_orientation(ai, SOUTH), W);
}

Test(test_ai, test_ai_6)
{
    ai_t *ai = ai_create(0, 0);

    ai->orientation = EAST;

    cr_assert_eq(ai_get_direction_from_orientation(ai, NORTH), W);
    cr_assert_eq(ai_get_direction_from_orientation(ai, EAST), S);
    cr_assert_eq(ai_get_direction_from_orientation(ai, WEST), N);
    cr_assert_eq(ai_get_direction_from_orientation(ai, SOUTH), E);
}
