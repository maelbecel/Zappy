/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_map
*/

#include <criterion/criterion.h>
#include "server.h"
#include "ai.h"
#include "utils.h"

server_t *get_server(int port)
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

Test(test_map, test_map_1)
{
    map_destroy(NULL);
}

Test(test_map, test_map_3)
{
    tile_t *tile = map_get_tile(NULL, 0, 0);

    cr_assert_null(tile);
}

Test(test_map, test_map_4)
{
    server_t *server = get_server(4243);
    cr_assert_not_null(server);
    cr_assert_not_null(server->map);

    client_t *client = client_create();
    client->type = AI;
    olist_add_node(server->clients, client);

    tile_t *tile2 = map_get_tile(server->map, 11, 11);
    cr_assert_null(tile2);

    tile_t *tile = map_get_tile(server->map, 0, 0);
    cr_assert_not_null(tile);
    cr_assert_eq(tile->x, 0);
    cr_assert_eq(tile->y, 0);

    olist_t *players = tile_get_players(server, tile);
    cr_assert_not_null(players);
    cr_assert_eq(players->size, 0);
    olist_destroy(players);

    olist_t *players_by_level = tile_get_players_by_level(server, tile, 1);
    cr_assert_not_null(players_by_level);
    cr_assert_eq(players_by_level->size, 0);
    olist_destroy(players_by_level);

    server_destroy(server);
}

Test(test_map, test_map_5)
{
    server_t *server = get_server(4244);
    cr_assert_not_null(server);
    cr_assert_not_null(server->map);

    client_t *client = client_create();
    client->type = AI;
    ai_t *ai = ai_create(5, 5);
    ai->x = 0;
    ai->y = 0;
    client->data = ai;
    olist_add_node(server->clients, client);

    tile_t *tile = map_get_tile(server->map, 0, 0);
    cr_assert_not_null(tile);
    cr_assert_eq(tile->x, 0);
    cr_assert_eq(tile->y, 0);

    olist_t *players = tile_get_players(server, tile);
    cr_assert_not_null(players);
    cr_assert_eq(players->size, 1);
    olist_destroy(players);

    olist_t *players_by_level = tile_get_players_by_level(server, tile, 1);
    cr_assert_not_null(players_by_level);
    cr_assert_eq(players_by_level->size, 1);
    olist_destroy(players_by_level);

    server_destroy(server);
}

Test(test_map, test_map_6)
{
    tile_add_player(NULL, NULL);
}

Test(test_map, test_map_7)
{
    tile_remove_player(NULL, NULL);
}

Test(test_map, test_map_8)
{
    server_t *server = get_server(4245);
    cr_assert_not_null(server);
    cr_assert_not_null(server->map);

    client_t *client = client_create();
    client->type = AI;
    ai_t *ai = ai_create(5, 5);
    ai->x = 0;
    ai->y = 0;
    client->data = ai;
    olist_add_node(server->clients, client);

    tile_add_player(server->map, client);
    tile_remove_player(server->map, client);

    server_destroy(server);
}

Test(test_map, test_map_9)
{
    server_t *server = get_server(4246);
    cr_assert_not_null(server);
    cr_assert_not_null(server->map);

    client_t *client = client_create();
    client->type = AI;
    ai_t *ai = ai_create(5, 5);
    ai->x = 11;
    ai->y = 11;
    client->data = ai;
    olist_add_node(server->clients, client);

    tile_add_player(server->map, client);
    tile_remove_player(server->map, client);

    server_destroy(server);
}

Test(test_map, test_map_10)
{
    server_t *server = get_server(4247);
    cr_assert_not_null(server);
    cr_assert_not_null(server->map);

    server->time->tick = 1;
    server->time->spawnItemLastTick = 1;
    map_spawn_items(server, true);

    server->time->tick = 10;
    server->time->spawnItemLastTick = 1;
    map_spawn_items(server, true);

    server->time->tick = 40;
    server->time->spawnItemLastTick = 1;
    map_spawn_items(server, true);
}
