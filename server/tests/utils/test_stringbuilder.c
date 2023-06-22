/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_stringbuilder
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(test_stringbuilder, test_stringbuilder_1)
{
    char **tab = malloc(sizeof(char *) * 3);

    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = NULL;

    char *str = stringbuilder(tab, 0);
    cr_assert_str_eq(str, "Hello World");
}

Test(test_stringbuilder, test_stringbuilder_2)
{
    char **tab = malloc(sizeof(char *) * 3);

    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = NULL;

    char *str = stringbuilder(tab, 1);
    cr_assert_str_eq(str, "World");
}
