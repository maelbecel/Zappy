/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_team
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "server.h"

Test(test_team, test_team_1)
{
    team_t *team = team_create("Team1");

    cr_assert(team != NULL);
    cr_assert_str_eq(team->name, "Team1");
    team_destroy(team);
}

Test(test_team, test_team_2)
{
    team_destroy(NULL);
    team_list_destructor(NULL);
}

Test(test_team, test_team_3)
{
    server_t *server = calloc(1, sizeof(server_t));

    cr_assert(server != NULL);
    server->teams = olist_create();
    cr_assert(server->teams != NULL);

    olist_add_node(server->teams, team_create("Team1"));
    olist_add_node(server->teams, team_create("Team2"));
    team_t *team = get_team_by_name(server, "Team1");
    cr_assert(team != NULL);
    cr_assert_str_eq(team->name, "Team1");

    team_t *unknown = get_team_by_name(server, "Unknown");
    cr_assert(unknown == NULL);
}

Test(test_team, test_team_4)
{
    server_t *server = calloc(1, sizeof(server_t));

    cr_assert(server != NULL);
    server->teams = olist_create();
    cr_assert(server->teams != NULL);

    team_t *team1 = team_create("Team1");

    olist_add_node(server->teams, team1);
    olist_add_node(server->teams, team_create("Team2"));
    team_t *team = team_get_by_id(server, team1->id);
    cr_assert_eq(team, team1);
    cr_assert_str_eq(team->name, "Team1");

    team_t *unknown = team_get_by_id(server, 256);
    cr_assert(unknown == NULL);
}
