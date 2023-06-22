/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_client
*/

#include <criterion/criterion.h>
#include "server.h"

static server_t *get_server(int port)
{
    options_t *options = init_options();
    server_t *server = NULL;

    options->port = port;
    options->width = 10;
    options->height = 10;
    options->teams_name = malloc(sizeof(char *) * 3);
    options->teams_name[0] = strdup("Team1");
    options->teams_name[1] = strdup("Team2");
    options->teams_name[2] = NULL;
    options->clients_nb = 1;
    options->freq = 100;
    server = server_create(options);
    del_options(options);
    return server;
}

Test(test_client, test_client_1)
{
    server_t *server = get_server(4267);

    client_t *client = client_create();
    client->id = 1;

    client_t *target = client_get_by_id(server, 1);
    cr_assert_eq(target, NULL);

    olist_add_node(server->clients, client);
    target = client_get_by_id(server, 1);
    cr_assert_eq(target, client);
}
