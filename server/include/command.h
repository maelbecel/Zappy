/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** command
*/

#ifndef COMMAND_H_
    #define COMMAND_H_

    #include "server.h"
    #include "client.h"
    #include "ai.h"
    #include "olog.h"

typedef struct command_s {
    char *command;
    int (*func)(client_t *client, server_t *server, char **args);
} command_t;

typedef struct incantation_resources_s {
    uint players_needed;
    uint linemate;
    uint deraumere;
    uint sibur;
    uint mendiane;
    uint phiras;
    uint thystame;
} incantation_resources_t;


int command_exec(client_t *client, server_t *server);
int command_exec_ai(client_t *client, server_t *server, char **args);
int execute_waiting_order(client_t *client, server_t *server);

// NONE commands
int select_team(client_t *client, server_t *server);

// AI commands
int forward(client_t *client, server_t *server, UNUSED char **args);
int right(client_t *client, server_t *server, UNUSED char **args);
int left(client_t *client, server_t *server, UNUSED char **args);
int inventory(client_t *client, server_t *server, UNUSED char **args);
int take(client_t *client, server_t *server, char **args);
int set(client_t *client, server_t *server, char **args);
int connect_nbr(client_t *client, server_t *server, UNUSED char **args);
int look(client_t *client, server_t *server, UNUSED char **args);
int fork_cmd(client_t *client, server_t *server, UNUSED char **args);
int eject(client_t *client, server_t *server, UNUSED char **args);
int incantation(client_t *client, server_t *server, UNUSED char **args);

void print_tile_content(tile_t *tile, client_t *client);
void look_north(client_t *client, server_t *server, ai_t *ai);
void look_south(client_t *client, server_t *server, ai_t *ai);
void look_west(client_t *client, server_t *server, ai_t *ai);
void look_east(client_t *client, server_t *server, ai_t *ai);

void eject_all_eggs(server_t *server, tile_t *tile);

void lock_unlock_players(olist_t *players, bool lock);
bool can_do_incantation(client_t *client, server_t *server);

void notif_graphic(client_t *client, server_t *server,
int (*func)(client_t *client, client_t *graphic));
void notif_ai(olist_t *players, char *msg);

// Graphic commands
int msz(client_t *client, server_t *server, UNUSED char **args);
int bct(client_t *client, server_t *server, char **args);
void print_bct(client_t *client, tile_t *tile, int x, int y);
void print_bct_for_all(server_t *server, tile_t *tile, int x, int y);
int mct(client_t *client, server_t *server, UNUSED char **args);
int tna(client_t *client, server_t *server, UNUSED char **args);
int sgt(client_t *client, server_t *server, UNUSED char **args);
int sst(client_t *client, server_t *server, char **args);
int ppo(client_t *client, server_t *server, char **args);
int do_ppo(client_t *client, client_t *graphic);
int plv(client_t *client, server_t *server, char **args);
int do_plv(client_t *client, client_t *graphic);
int pnw(client_t *graphic, client_t *target, server_t *server);
int welcome(client_t *client, server_t *server);
int pin(client_t *client, server_t *server, char **args);
int do_pin(client_t *client, client_t *graphic);
int pgt(server_t *server, ulong client_id, item_t item);
int pdr(server_t *server, ulong client_id, item_t item);
int ebo(ulong egg_id, client_t *graphic);
int pfk(client_t *client, client_t *graphic);
int enw(client_t *graphic, egg_t *egg, ulong client_id);
int pex(client_t *client, client_t *graphic);
int edi(ulong egg_id, client_t *graphic);
int pic(server_t *server, olist_t *players, uint x, uint y);
int pie(server_t *server, client_t *client, uint result);

// ALL commands
void client_disconnect(server_t *server, client_t *client);

#endif /* !COMMAND_H_ */
