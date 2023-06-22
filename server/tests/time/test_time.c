/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_time
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include "server.h"

Test(test_time, test_time_1)
{
    time_manager_t *time = time_create(100);

    cr_assert(time != NULL);
    cr_assert(time->freq == 100);
    cr_assert(time->secPerTick == 0.01);
    time_destroy(time);
}

Test(test_time, test_time_2)
{
    time_destroy(NULL);
}

Test(test_time, test_time_3)
{
    time_manager_t *time = time_create(100);

    cr_assert(time != NULL);
    sleep(1);
    time_update(time);
    cr_assert(time->tick == 100);
    time_destroy(time);
}
