/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** broadcast
*/

#include <criterion/criterion.h>
#include "command.h"

Test(test_broadcast, test_broadcast_1)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 1;
    emet->y = 1;

    rec->x = 1;
    rec->y = 9;
    cr_assert_eq(get_direction(emet, rec), 1);
}

Test(test_broadcast, test_broadcast_2)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 1;
    emet->y = 9;

    rec->x = 1;
    rec->y = 1;
    cr_assert_eq(get_direction(emet, rec), 5);
}

Test(test_broadcast, test_broadcast_3)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 4;
    emet->y = 5;

    rec->x = 7;
    rec->y = 5;
    cr_assert_eq(get_direction(emet, rec), 3);
}

Test(test_broadcast, test_broadcast_4)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 7;
    emet->y = 5;

    rec->x = 4;
    rec->y = 5;
    cr_assert_eq(get_direction(emet, rec), 7);
}

Test(test_broadcast, test_broadcast_5)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 5;
    emet->y = 2;

    rec->x = 7;
    rec->y = 4;
    cr_assert_eq(get_direction(emet, rec), 2);
}

Test(test_broadcast, test_broadcast_6)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 7;
    emet->y = 4;

    rec->x = 5;
    rec->y = 2;
    cr_assert_eq(get_direction(emet, rec), 6);
}

Test(test_broadcast, test_broadcast_7)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 7;
    emet->y = 2;

    rec->x = 5;
    rec->y = 4;
    cr_assert_eq(get_direction(emet, rec), 8);
}

Test(test_broadcast, test_broadcast_8)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 5;
    emet->y = 4;

    rec->x = 7;
    rec->y = 2;
    cr_assert_eq(get_direction(emet, rec), 4);
}

Test(test_broadcast, test_broadcast_9)
{
    ai_t *emet = ai_create(1, 1);
    ai_t *rec = ai_create(1, 1);

    emet->x = 0;
    emet->y = 0;

    rec->x = 0;
    rec->y = 0;
    cr_assert_eq(get_direction(emet, rec), 0);
}
