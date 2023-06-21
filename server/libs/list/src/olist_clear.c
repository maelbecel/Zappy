/*
** EPITECH PROJECT, 2023
** list
** File description:
** olist_clear.c
*/

#include <stdlib.h>
#include "olist.h"

/**
 * @brief Clear the list
 * Clear the list and free all nodes and their data
 * @param list
 */
void olist_clear(olist_t *list)
{
    olist_node_t *tmp = NULL;

    if (list == NULL)
        return;
    tmp = list->head;
    for (uint i = 0; i < list->size; i++) {
        if (tmp->next == NULL) {
            (tmp->data) ? free(tmp->data) : 0;
            (tmp) ? free(tmp) : 0;
            break;
        }
        tmp = tmp->next;
        (tmp->prev->data) ? free(tmp->prev->data) : 0;
        (tmp->prev) ? free(tmp->prev) : 0;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void olist_clear_wdfree(olist_t *list)
{
    olist_node_t *tmp = NULL;

    if (list == NULL)
        return;
    tmp = list->head;
    for (uint i = 0; i < list->size; i++) {
        if (tmp->next == NULL) {
            free(tmp);
            break;
        }
        tmp = tmp->next;
        free(tmp->prev);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
