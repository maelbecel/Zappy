/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <stdbool.h>
    #include <sys/select.h>
    #include <sys/time.h>
    #include "options.h"
    #include "olist.h"
    #include "osocket.h"
    #include "map.h"

    #ifndef NULL
        #define NULL (0)
    #endif

    #ifndef EXIT_SUCCESS
        #define EXIT_SUCCESS 0
    #endif

    #define UNUSED __attribute__((unused))
    #define EXIT_FAILTEK 84

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef signed long long llong;
typedef unsigned long long ullong;

typedef struct select_s {
    fd_set readfds;
    fd_set writefds;
    uint maxfd;
} select_t;

typedef struct time_manager_s {
    uint tick;
    uint freq;
    struct timeval last;
    struct timeval current;
    struct timeval timeout;
    double secPerTick;
    uint actionLastTick;
    uint spawnItemLastTick;
} time_manager_t;

typedef struct egg_s {
    ulong id;
    ulong team_id;
    uint x;
    uint y;
    ulong player_id;
    bool hatched;
} egg_t;

typedef struct server_s {
    socket_t *socket;
    bool running;
    olist_t *clients;
    olist_t *teams;
    olist_t *eggs;
    uint max_team_size;
    map_t *map;
    select_t *select;
    time_manager_t *time;
} server_t;

typedef struct team_s {
    ulong id;
    olist_t *clients;
    char *name;
    uint team_size;
    uint eggs_size;
} team_t;

int main_loop(server_t *server);

/**
 * @brief Create a server object
 * Start the server socket and listen for new connections
 * with the given port in options
 *
 * @param options Options object
 * @return server_t* Allocated server object
 */
server_t *server_create(options_t *options);

/**
 * @brief Destroy a server object
 * Destroy all clients and teams
 * Close the server socket
 * Free the server object
 *
 * @param server
 */
void server_destroy(server_t *server);

/**
 * @brief Accept a client connection and
 * initialize a client_t structure
 * This method also add the client to the server's clients list
 *
 * @param server
 * @return int EXIT_SUCCESS or EXIT_FAILTEK
 */
int client_accept(server_t *server);

/**
 * @brief Read data from all clients socket
 * and handle it
 *
 * @param server
 * @return int
 */
int client_read(server_t *server);

/**
 * @brief Create new team
 *
 * @param name Name of team (used to identify it)
 * @return team_t* Allocated team object
 */
team_t *team_create(char *name);

/**
 * @brief Destroy a team object
 * Free the team object
 * @param team
 */
void team_destroy(team_t *team);

/**
 * @brief Get a team by its id
 *
 * @param server
 * @param id
 * @return team_t*
 */
team_t *team_get_by_id(server_t *server, ulong id);

/**
 * @brief Get the team by name
 *
 * @param server Link to server object
 * @param name Name of team
 * @return team_t* Return NULL if not found
 */
team_t *get_team_by_name(server_t *server, char *name);

/**
 * @brief Create a time manager object
 *
 * @param freq Frequency of ticks
 * @return time_manager_t*
 */
time_manager_t *time_create(uint freq);

/**
 * @brief Destroy a time manager object
 * Free the time manager object
 * @param time time manager object
 */
void time_destroy(time_manager_t *time);

/**
 * @brief Update time
 * Add ticks based on frequency and elapsed time
 * @param time time manager object
 */
void time_update(time_manager_t *time);

/**
 * @brief Update actions for all clients
 *
 * @param server
 */
void action_update(server_t *server);

/**
 * @brief Create a new action
 *
 * @param name Name of action
 * @param server Link to server object
 * @param client Link to client object
 * @param duration Duration
 * @return action_t*
 */
action_t *action_create(char *name, server_t *server, client_t *client,
ulong duration);

/**
 * @brief Destroy an action object
 * Free the action object
 * @param action
 */
void action_destroy(action_t *action);

/**
 * @brief Get a client by its id
 *
 * @param server
 * @param id
 * @return client_t*
 */
client_t *client_get_by_id(server_t *server, ulong id);

/**
 * @brief Spawn items on the map
 *
 * @param server
 */
void map_spawn_items(server_t *server, bool checkTime);

/**
 * @brief Create a new egg
 *
 * @param team_id Team which create the egg
 * @param x pos x of egg
 * @param y pos y of egg
 * @return egg_t* Allocated egg object
 */
egg_t *egg_create(ulong team_id, uint x, uint y, ulong player_id);

/**
 * @brief Destroy an egg object
 *
 * @param egg
 */
void egg_destroy(egg_t *egg);

/**
 * @brief Check if at least one egg is in the team
 *
 * @param team_id Team id
 * @param server Link to server object
 * @return true If at least one egg is in the team
 * @return false If no egg is in the team
 */
bool egg_is_egg_in_team(ulong team_id, server_t *server);

/**
 * @brief Get random egg in team
 *
 * @param team_id Team id
 * @param server Link to server object
 * @return egg_t* Return NULL if no egg is in the team
 */
egg_t *egg_get_one_in_team(ulong team_id, server_t *server);

/**
 * @brief Add an egg to a team
 *
 * @param server Link to server object
 * @param team_id Team id
 */
void egg_add_to_team(server_t *server, ulong team_id);

void action_set_to_client(server_t *server, client_t *client, action_t *action);
void time_update_timeout(server_t *server, double action_time);

#endif /* !SERVER_H_ */
