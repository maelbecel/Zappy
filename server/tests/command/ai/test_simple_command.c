/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** test_simple_command
*/

#include <criterion/criterion.h>
#include "command.h"
#include "wbuffer.h"

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

static client_t *get_basic_ai_client(server_t *server)
{
    client_t *client = client_create();

    client->socket = ocreate_socket_with_fd(1);
    client->type = AI;

    team_t *team = (team_t *) server->teams->head->data;
    olist_add_node(team->clients, client);
    team->team_size++;
    client->team_id = team->id;

    ai_t *ai = ai_create(0, 0);
    ai->orientation = NORTH;
    ai->x = 5;
    ai->y = 5;
    client->data = ai;
    return client;
}

static char *get_message(client_t *client)
{
    char *message = wbuffer_empty(client);

    return message;
}

Test(test_simple_command_ai, test_simple_command_ai_1)
{
    server_t *server = get_server(4270);
    client_t *client = get_basic_ai_client(server);

    connect_nbr(client, server, NULL);
    cr_assert_str_eq(get_message(client), "0\n");

    client->team_id = 3456;
    connect_nbr(client, server, NULL);
    cr_assert_str_eq(get_message(client), "0\n");
}

Test(test_simple_command_ai, test_simple_command_ai_2)
{
    server_t *server = get_server(4271);
    client_t *client = get_basic_ai_client(server);

    ((ai_t *) client->data)->orientation = NORTH;
    left(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, WEST);
    cr_assert_str_eq(get_message(client), "ok\n");

    ((ai_t *) client->data)->orientation = SOUTH;
    left(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, EAST);
    cr_assert_str_eq(get_message(client), "ok\n");

    ((ai_t *) client->data)->orientation = WEST;
    left(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, SOUTH);
    cr_assert_str_eq(get_message(client), "ok\n");

    ((ai_t *) client->data)->orientation = EAST;
    left(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, NORTH);
    cr_assert_str_eq(get_message(client), "ok\n");

    left(client, server, NULL);
    client->current_action->data[1] = NULL;
    client->current_action->callback(client->current_action);
    cr_assert_str_eq(get_message(client), "ko\n");
}

Test(test_simple_command_ai, test_simple_command_ai_3)
{
    server_t *server = get_server(4272);
    client_t *client = get_basic_ai_client(server);

    ((ai_t *) client->data)->orientation = NORTH;
    right(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, EAST);
    cr_assert_str_eq(get_message(client), "ok\n");

    ((ai_t *) client->data)->orientation = SOUTH;
    right(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, WEST);
    cr_assert_str_eq(get_message(client), "ok\n");

    ((ai_t *) client->data)->orientation = WEST;
    right(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, NORTH);
    cr_assert_str_eq(get_message(client), "ok\n");

    ((ai_t *) client->data)->orientation = EAST;
    right(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->orientation, SOUTH);
    cr_assert_str_eq(get_message(client), "ok\n");

    right(client, server, NULL);
    client->current_action->data[1] = NULL;
    client->current_action->callback(client->current_action);
    cr_assert_str_eq(get_message(client), "ko\n");
}

Test(test_simple_command_ai, test_simple_command_ai_4)
{
    server_t *server = get_server(4273);
    client_t *client = get_basic_ai_client(server);

    uint ypos = ((ai_t *) client->data)->y;
    ((ai_t *) client->data)->orientation = NORTH;
    forward(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->y, ypos - 1);
    cr_assert_str_eq(get_message(client), "ok\n");

    ypos = ((ai_t *) client->data)->y;
    ((ai_t *) client->data)->orientation = SOUTH;
    forward(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->y, ypos + 1);
    cr_assert_str_eq(get_message(client), "ok\n");

    uint xpos = ((ai_t *) client->data)->x;
    ((ai_t *) client->data)->orientation = WEST;
    forward(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->x, xpos - 1);
    cr_assert_str_eq(get_message(client), "ok\n");

    xpos = ((ai_t *) client->data)->x;
    ((ai_t *) client->data)->orientation = EAST;
    forward(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_eq(((ai_t *) client->data)->x, xpos + 1);
    cr_assert_str_eq(get_message(client), "ok\n");

    forward(client, server, NULL);
    client->current_action->data[1] = NULL;
    client->current_action->callback(client->current_action);
    cr_assert_str_eq(get_message(client), "ko\n");
}

Test(test_simple_command_ai, test_simple_command_ai_5)
{
    server_t *server = get_server(4274);
    client_t *client = get_basic_ai_client(server);

    inventory(client, server, NULL);
    client->current_action->callback(client->current_action);
    cr_assert_str_eq(get_message(client), "[ food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0 ]\n");

    inventory(client, server, NULL);
    client->current_action->data[0] = NULL;
    client->current_action->callback(client->current_action);

    inventory(client, server, NULL);
    client->data = NULL;
    client->current_action->callback(client->current_action);
}
