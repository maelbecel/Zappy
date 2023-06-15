/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** command_exec_ai
*/

#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "client.h"
#include "command.h"
#include "olog.h"
#include "utils.h"
#include "wbuffer.h"

static const command_t ai_commands[] = {
    {"Forward", &forward},
    {"Right", &right},
    {"Left", &left},
    {"Inventory", &inventory},
    {"Take", &take},
    {"Set", &set},
    {"Connect_nbr", &connect_nbr},
    {"Look", &look},
    {"Fork", &fork_cmd},
    {"Eject", &eject},
    {"Incantation", &incantation},
    {"Broadcast", &broadcast},
    {NULL, NULL}
};

static void ending_executing(client_t *client, char **args, bool found)
{
    if (!found)
        wbuffer_add_msg(client, "ko\n");
    for (uint i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}

int execute_waiting_order(client_t *client, server_t *server)
{
    char **args = NULL;
    bool found = false;

    if (!client->waiting_orders->head)
        return 0;
    args = ostr_to_array(client->waiting_orders->head->data, " ");
    if (!args)
        return EXIT_FAILTEK;
    for (uint i = 0; ai_commands[i].command; i++) {
        olist_remove_node(client->waiting_orders, 0);
        if (strcmp(ai_commands[i].command, args[0]) == 0) {
            ai_commands[i].func(client, server, args);
            found = true;
            break;
        }
    }
    ending_executing(client, args, found);
    return 0;
}

int command_exec_ai(client_t *client, server_t *server, char **args)
{
    ai_t *ai = client->data;

    if (!ai)
        return EXIT_FAILTEK;
    if (strlen(client->buffer) == 0)
        return 0;
    OLOG_INFO("AI id#%ld fd#%d> %s", client->id, client->socket->fd,
    client->buffer);
    if ((client->current_action != NULL || ai->incantation)
    && client->waiting_orders->size < 10) {
        olist_add_node(client->waiting_orders, strdup(client->buffer));
        return 0;
    }
    if (client->waiting_orders->size >= 10)
        return 0;
    for (uint i = 0; ai_commands[i].command; i++)
        if (strcmp(ai_commands[i].command, args[0]) == 0)
            return ai_commands[i].func(client, server, args);
    wbuffer_add_msg(client, "ko\n");
    return 0;
}
