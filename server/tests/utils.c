/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** utils
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(tests_utils, tests_utils_1)
{
    char **args = ostr_to_array(NULL, " ");

    cr_assert_null(args);
}

Test(tests_utils, tests_utils_2)
{
    char **args = ostr_to_array("test", NULL);

    cr_assert_null(args);
}

Test(tests_utils, tests_utils_3)
{
    char **args = ostr_to_array("test", " ");

    cr_assert_not_null(args);
    cr_assert_str_eq(args[0], "test");
    cr_assert_null(args[1]);
}

Test(tests_utils, tests_utils_4)
{
    uint id = generate_id();

    cr_assert(id > 0);
}
