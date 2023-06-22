/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_array_size
*/

#include <criterion/criterion.h>
#include "utils.h"

Test(test_array_size, test_array_size_1)
{
    char **tab = malloc(sizeof(char *) * 3);

    tab[0] = strdup("Hello");
    tab[1] = strdup("World");
    tab[2] = NULL;

    int size = array_size(tab);
    cr_assert_eq(size, 2);
}

Test(test_array_size, test_array_size_2)
{
    int size = array_size(NULL);
    cr_assert_eq(size, 0);
}
