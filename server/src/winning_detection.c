/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** winning_detection
*/

#include "server.h"
#include "ai.h"
#include "wbuffer.h"

static uint get_players_lvl8(team_t *team)
{
    uint players_lvl8 = 0;
    client_t *client = NULL;
    ai_t *ai = NULL;

    OLIST_FOREACH(team->clients, node) {
        client = (client_t *)node->data;
        if (!client)
            continue;
        ai = (ai_t *)client->data;
        if (!ai)
            continue;
        if (ai->level == 8)
            players_lvl8++;
    }
    return players_lvl8;
}

static void notif_all(server_t *server, team_t *team)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = (client_t *)node->data;
        if (!client || client->type != GRAPHIC)
            continue;
        wbuffer_add_message(client, "seg %s\n", team->name);
    }
}

bool check_win_condition(server_t *server)
{
    team_t *team = NULL;
    uint players_lvl8 = 0;

    OLIST_FOREACH(server->teams, node) {
        team = (team_t *)node->data;
        if (!team)
            continue;
        players_lvl8 = get_players_lvl8(team);
        if (players_lvl8 >= 6) {
            notif_all(server, team);
            server->running = false;
            return true;
        }
    }
    return false;
}
