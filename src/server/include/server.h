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

typedef struct server_s {
    socket_t *socket;
    bool running;
    olist_t *clients;
    olist_t *teams;
    uint max_team_size;
    map_t *map;
    uint freq;
    select_t *select;
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

#endif /* !SERVER_H_ */
