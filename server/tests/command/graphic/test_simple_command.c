/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_simple_command
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "command.h"
#include "wbuffer.h"
#include "utils.h"

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

static client_t *get_graphic(void)
{
    client_t *graphic = client_create();
    graphic->socket = ocreate_socket_with_fd(1);
    graphic->type = GRAPHIC;

    return graphic;
}

static char *get_message(client_t *client)
{
    char *message = wbuffer_empty(client);

    return message;
}

Test(test_simple_command, test_simple_command_1)
{
    client_t *graphic = get_graphic();

    ebo(4, graphic);
    cr_assert_str_eq(get_message(graphic), "ebo 4\n");
}

Test(test_simple_command, test_simple_command_2)
{
    client_t *graphic = get_graphic();

    edi(4, graphic);
    cr_assert_str_eq(get_message(graphic), "edi 4\n");
}

Test(test_simple_command, test_simple_command_3)
{
    client_t *graphic = get_graphic();

    egg_t *egg = egg_create(1, 2, 3, 4);

    egg->id = 5;
    enw(graphic, egg, 5);
    enw(NULL, egg, 5);
    cr_assert_str_eq(get_message(graphic), "enw 5 5 2 3\n");
}

Test(test_simple_command, test_simple_command_4)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4247);

    msz(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "msz 10 10\n");
}

Test(test_simple_command, test_simple_command_5)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4249);

    olist_add_node(server->clients, graphic);
    pdr(server, 4, 5);
    cr_assert_str_eq(get_message(graphic), "pdr 4 5\n");
}

Test(test_simple_command, test_simple_command_6)
{
    client_t *graphic = get_graphic();
    client_t *client = client_create();

    client->id = 4;
    pex(client, graphic);
    cr_assert_str_eq(get_message(graphic), "pex 4\n");
}

Test(test_simple_command, test_simple_command_7)
{
    client_t *graphic = get_graphic();
    client_t *client = client_create();

    client->id = 4;
    pfk(client, graphic);
    pfk(NULL, graphic);
    cr_assert_str_eq(get_message(graphic), "pfk 4\n");
}

Test(test_simple_command, test_simple_command_8)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4250);

    olist_add_node(server->clients, graphic);
    pgt(server, 4, 5);
    cr_assert_str_eq(get_message(graphic), "pgt 4 5\n");
}

Test(test_simple_command, test_simple_command_9)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4257);

    olist_add_node(server->clients, graphic);
    olist_t *players = olist_create();
    client_t *client = client_create();
    client->id = 4;
    ai_t *ai = ai_create(0, 0);
    ai->level = 1;
    client->data = ai;
    olist_add_node(players, client);
    olist_add_node(server->clients, client);
    pic(server, players, 0, 0);
    cr_assert_str_eq(get_message(graphic), "pic 0 0 1 4\n");
}

Test(test_simple_command, test_simple_command_10)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4258);

    olist_add_node(server->clients, graphic);
    client_t *client = client_create();
    client->id = 4;
    client->type = AI;
    pie(server, client, 0);
    ai_t *ai = ai_create(0, 0);
    ai->level = 1;
    client->data = ai;
    olist_add_node(server->clients, client);

    pie(server, client, 0);
    cr_assert_str_eq(get_message(graphic), "pie 0 0 0\n");
}

Test(test_simple_command, test_simple_command_11)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4259);

    client_t *client = client_create();
    client->id = 4;
    client->type = AI;

    do_pin(client, graphic);
    cr_assert_str_eq(get_message(graphic), "sbp\n");
    ai_t *ai = ai_create(0, 0);
    ai->level = 1;
    client->data = ai;
    do_pin(client, graphic);
    cr_assert_str_eq(get_message(graphic), "pin 4 0 0 10 0 0 0 0 0 0\n");

    olist_add_node(server->clients, client);
    pin(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "sbp\n");
    char **args = calloc(sizeof(char *), 3);
    args[0] = strdup("pin");
    args[1] = strdup("5");
    pin(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    args[1] = strdup("4");
    pin(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "pin 4 0 0 10 0 0 0 0 0 0\n");
}

Test(test_simple_command, test_simple_command_12)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4260);

    client_t *client = client_create();
    client->id = 4;
    client->type = AI;
    do_plv(client, graphic);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    ai_t *ai = ai_create(0, 0);
    ai->level = 1;
    client->data = ai;
    olist_add_node(server->clients, client);

    plv(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    char **args = calloc(sizeof(char *), 3);
    args[0] = strdup("plv");
    args[1] = strdup("5");
    plv(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    args[1] = strdup("4");
    plv(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "plv 4 1\n");
}

Test(test_simple_command, test_simple_command_13)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4261);

    client_t *client = client_create();
    team_t *team = (team_t *) server->teams->head->data;
    client->id = 4;
    client->type = AI;
    client->team_id = 0;

    pnw(graphic, client, server);

    ai_t *ai = ai_create(0, 0);
    ai->level = 1;
    ai->orientation = NORTH;
    client->data = ai;
    pnw(graphic, client, server);

    client->team_id = team->id;
    pnw(graphic, client, server);
    cr_assert_str_eq(get_message(graphic), "pnw 4 0 0 1 1 Team1\n");
}

Test(test_simple_command, test_simple_command_14)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4262);

    client_t *client = client_create();
    client->id = 4;
    client->type = AI;

    ppo(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    char **args = calloc(sizeof(char *), 3);
    args[0] = strdup("ppo");
    args[1] = strdup("5");

    ppo(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    ai_t *ai = ai_create(0, 0);
    ai->level = 1;
    ai->orientation = NORTH;
    olist_add_node(server->clients, client);
    args[1] = strdup("4");

    ppo(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "sbp\n");
    client->data = ai;

    ppo(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "ppo 4 0 0 1\n");
}

Test(test_simple_command, test_simple_command_15)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4248);

    sgt(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "sgt 100\n");
}

Test(test_simple_command, test_simple_command_16)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4250);

    sst(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    char **args = calloc(sizeof(char *), 3);
    args[0] = strdup("sst");
    args[1] = strdup("1");
    sst(graphic, server, args);
    cr_assert_str_eq(get_message(graphic), "sbp\n");

    char **args2 = calloc(sizeof(char *), 3);
    args2[0] = strdup("sst");
    args2[1] = strdup("10");
    sst(graphic, server, args2);
    cr_assert_str_eq(get_message(graphic), "sst 10\n");
}

Test(test_simple_command, test_simple_command_17)
{
    client_t *graphic = get_graphic();
    server_t *server = get_server(4251);

    tna(graphic, server, NULL);
    cr_assert_str_eq(get_message(graphic), "tna Team1\ntna Team2\n");
}
