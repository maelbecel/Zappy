/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** pic
*/

#include "command.h"
#include "wbuffer.h"

static void print_players(olist_t *players, client_t *client)
{
    client_t *tmp = NULL;
    ai_t *ai = NULL;
    bool first = true;

    OLIST_FOREACH(players, node) {
        tmp = node->data;
        if (!tmp)
            continue;
        ai = tmp->data;
        if (!ai)
            continue;
        if (first)
            wbuffer_add_message(client, " %d", ai->level);
        first = false;
        wbuffer_add_message(client, " %d", tmp->id);
    }
}

int pic(server_t *server, olist_t *players, uint x, uint y)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = node->data;
        if (!client || client->type != GRAPHIC)
            continue;
        wbuffer_add_message(client, "pic %d %d", x, y);
        print_players(players, client);
        wbuffer_add_msg(client, "\n");
    }
    return 0;
}
