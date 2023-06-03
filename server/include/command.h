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

typedef struct ai_command_s {
    char *command;
    int (*func)(client_t *client, server_t *server, ai_t *ai, char **args);
} ai_command_t;

typedef struct graphic_command_s {
    char *command;
    int (*func)(client_t *client, server_t *server, char **args);
} graphic_command_t;

int command_exec(client_t *client, server_t *server);

// NONE commands
int select_team(client_t *client, server_t *server);



// ALL commands
void client_disconnect(server_t *server, client_t *client);

#endif /* !COMMAND_H_ */
