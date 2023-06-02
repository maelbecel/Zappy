/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #define MAX_READ_SIZE 4096

    #include "osocket.h"
    #include "olist.h"

typedef unsigned long ulong;

typedef enum {
    AI,
    GRAPHIC,
    NONE
} client_type_t;

typedef struct action_s {
    char *name;
    char **args;
    uint duration;
    char *response;
    void (*callback)(struct action_s *action, socket_t *socket);
} action_t;

typedef struct client_s {
    ulong id;
    socket_t *socket;
    char *buffer;
    ulong team_id;
    client_type_t type;
    void *data;
    olist_t *actions_queue;
    action_t *current_action;
} client_t;

/**
 * @brief Initialize a client_t structure
 *
 * @return client_t*
 */
client_t *client_create(void);

/**
 * @brief Destroy a client_t structure
 * and free its memory. This method also
 * close its socket
 *
 * @param client
 */
void client_destroy(client_t *client);

#endif /* !CLIENT_H_ */
