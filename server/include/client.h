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

/**
 * @brief Structure that represent an action (command from ai)
 * data can be all data needed by action.
 * Be careful, datas can be different for each action
 *
 * Usually, data[0] is the client and data[1] is the server
 * You are free to use it as you want
 *
 * Callback is called when duration is <= 0
 * Duration decrease by 1 each server tick
 */
typedef struct action_s {
    char *name;
    void **data;
    long duration;
    void (*callback)(struct action_s *action);
} action_t;

typedef struct client_s {
    ulong id;
    socket_t *socket;
    char *buffer;
    ulong team_id;
    client_type_t type;
    void *data;
    olist_t *waiting_orders;
    olist_t *wbuffer;
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

/**
 * @brief Destroy a list of client_t structure
 *
 * @param list
 */
void client_list_destroy(olist_t *list);

#endif /* !CLIENT_H_ */
