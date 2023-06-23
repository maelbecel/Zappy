/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_ostr_to_array
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(test_ostr_to_array, test_ostr_to_array_1)
{
    char *str = strdup("Hello World");
    char **tab = ostr_to_array(str, " ");

    cr_assert_str_eq(tab[0], "Hello");
    cr_assert_str_eq(tab[1], "World");
    cr_assert_eq(tab[2], NULL);
}

Test(test_ostr_to_array, test_ostr_to_array_2)
{
    char **tab = ostr_to_array(NULL, " ");

    cr_assert_eq(tab, NULL);
}
