/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** fork
*/

#include "command.h"
#include "wbuffer.h"

static void create_egg(server_t *server, client_t *client, ai_t *ai)
{
    egg_t *egg = egg_create(client->team_id, ai->x, ai->y, client->id);

    if (!egg) {
        OLOG_FATALA("Fork action: cannot create egg");
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    olist_add_node(server->eggs, egg);
    wbuffer_add_msg(client, "ok\n");
    egg_add_to_team(server, client->team_id);
    OLIST_FOREACH(server->clients, node) {
        client_t *tmp = (client_t *)node->data;
        if (!tmp)
            continue;
        if (tmp->type == GRAPHIC)
            enw(tmp, egg, client->id);
    }
}

static void do_fork(action_t *action)
{
    client_t *client = action->data[0];
    server_t *server = action->data[1];
    ai_t *ai = NULL;

    if (!server || !client) {
        OLOG_FATALA("Fork action: missing data");
        return;
    }
    ai = client->data;
    if (!ai) {
        OLOG_FATALA("Fork action: missing data");
        wbuffer_add_msg(client, "ko\n");
        return;
    }
    create_egg(server, client, ai);
}

int fork_cmd(client_t *client, server_t *server, UNUSED char **args)
{
    action_t *action = action_create("Fork", server, client, 42);

    if (!action)
        return 84;
    action->callback = &do_fork;
    action_set_to_client(server, client, action);
    notif_graphic(client, server, &pfk);
    return 0;
}
