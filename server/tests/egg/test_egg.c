/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_egg
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

Test(test_egg, test_egg_1)
{
    egg_t *egg = egg_create(1, 2, 3, 4);

    cr_assert_eq(egg->team_id, 1);
    cr_assert_eq(egg->x, 2);
    cr_assert_eq(egg->y, 3);
    cr_assert_eq(egg->player_id, 4);

    egg_destroy(egg);
}

Test(test_egg, test_egg_2)
{
    egg_destroy(NULL);
    egg_list_destructor(NULL);
}

Test(test_egg, test_egg_3)
{
    egg_add_to_team(NULL, 1);
}

Test(test_egg, test_egg_4)
{
    server_t *server = get_server(4242);
    team_t *team = (team_t *) server->teams->head->data;
    team_t *team2 = (team_t *) server->teams->tail->data;
    egg_t *egg = egg_create(team->id, 0, 0, 4);

    egg_add_to_team(server, 1);
    egg_add_to_team(server, team->id);
    olist_add_node(server->eggs, egg);
    cr_assert_eq(egg->team_id, team->id);

    cr_assert_eq(egg_is_egg_in_team(team->id, server), true);
    cr_assert_eq(egg_is_egg_in_team(4, server), false);

    egg_t *team_not_found = egg_get_one_in_team(4, server);
    cr_assert_eq(team_not_found, NULL);

    egg_t *egg_not_found = egg_get_one_in_team(team2->id, server);
    cr_assert_eq(egg_not_found, NULL);

    egg_t *new_egg = egg_get_one_in_team(team->id, server);
    cr_assert_eq(new_egg->team_id, team->id);

    egg_list_destructor(server->eggs);
}
