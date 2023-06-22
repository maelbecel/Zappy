/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** server
*/

#include <criterion/criterion.h>
#include "server.h"
#include "options.h"

Test(test_server, test_server_1)
{
    options_t *options = init_options();
    server_t *server = NULL;

    cr_assert(options != NULL);
    options->port = 4242;
    options->width = 10;
    options->height = 10;
    options->teams_name = malloc(sizeof(char *) * 3);
    options->teams_name[0] = strdup("Team1");
    options->teams_name[1] = strdup("Team2");
    options->teams_name[2] = NULL;
    options->clients_nb = 1;
    options->freq = 100;
    server = server_create(options);
    cr_assert(server != NULL);
    cr_assert(server->max_team_size == 1);
    cr_assert(server->time->freq == 100);
    del_options(options);
    server_destroy(server);
}

Test(test_server, test_server_2)
{
    del_options(NULL);
    server_destroy(NULL);
}
