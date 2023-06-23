/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_wbuffer
*/

#include <criterion/criterion.h>
#include "wbuffer.h"

Test(test_wbuffer, test_wbuffer_1)
{
    client_t *client = client_create();
    char *message = NULL;

    wbuffer_add_msg(client, "Hello");
    message = wbuffer_empty(client);
    cr_assert_str_eq(message, "Hello");
}

Test(test_wbuffer, test_wbuffer_2)
{
    char *message = wbuffer_empty(NULL);

    cr_assert_eq(message, NULL);
}

Test(test_wbuffer, test_wbuffer_3)
{
    client_t *client = client_create();

    wbuffer_add_msg(client, NULL);
}
