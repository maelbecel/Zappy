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
    double secPerTick;
    uint actionLastTick;
} time_manager_t;

typedef struct server_s {
    socket_t *socket;
    bool running;
    olist_t *clients;
    olist_t *teams;
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
 * @brief Get a client by its id
 *
 * @param server
 * @param id
 * @return client_t*
 */
client_t *client_get_by_id(server_t *server, ulong id);

#endif /* !SERVER_H_ */
