/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** team_create
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "utils.h"

team_t *team_create(char *name)
{
    team_t *team = calloc(1, sizeof(team_t));

    if (!team)
        return NULL;
    team->name = strdup(name);
    if (!team->name) {
        free(team);
        return NULL;
    }
    team->clients = olist_create();
    team->clients->destructor = &default_destructor_no_free;
    team->id = generate_id();
    team->team_size = 0;
    return team;
}
