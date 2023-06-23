/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** *
*/

#include "server.h"
#include "wbuffer.h"

static const char *seasons[] = {
    "NONE",
    "spring",
    "summer",
    "autumn",
    "winter"
};

static void send_update(server_t *server)
{
    client_t *client = NULL;

    OLIST_FOREACH(server->clients, node) {
        client = (client_t *)node->data;
        if (!client || client->type != GRAPHIC)
            continue;
        wbuffer_add_message(client, SEASON_CHANGING_MSG,
            server->time->currentSeason);
    }
}

void season_update(server_t *server)
{
    uint tickDiff = server->time->tick - server->time->seasonLastTick;

    if (tickDiff == 0)
        return;
    if (tickDiff < 1260)
        return;
    switch (server->time->currentSeason) {
        case SPRING: server->time->currentSeason = SUMMER; break;
        case SUMMER: server->time->currentSeason = AUTUMN; break;
        case AUTUMN: server->time->currentSeason = WINTER; break;
        case WINTER: server->time->currentSeason = SPRING; break;
    }
    OLOG_INFO("Season changed to %s", seasons[server->time->currentSeason]);
    server->time->seasonLastTick = server->time->tick;
    send_update(server);
}
