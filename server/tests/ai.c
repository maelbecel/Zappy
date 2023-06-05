/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** ai
*/

#include <criterion/criterion.h>
#include "ai.h"

Test(test_ai, test_ai_1)
{
    ai_t *ai = ai_create(10, 10);

    cr_assert_not_null(ai);
    cr_assert(ai->x < 10);
    cr_assert(ai->y < 10);
    cr_assert(ai->level == 1);
    ai_destroy(ai);
}
