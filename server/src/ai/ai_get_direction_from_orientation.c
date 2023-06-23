/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** ai_get_direction_from_orientation
*/

#include "ai.h"

static int get_from_north(orientation_t orientation)
{
    if (orientation == NORTH)
        return S;
    if (orientation == EAST)
        return W;
    if (orientation == SOUTH)
        return N;
    return E;
}

static int get_from_south(orientation_t orientation)
{
    if (orientation == NORTH)
        return N;
    if (orientation == EAST)
        return E;
    if (orientation == SOUTH)
        return S;
    return W;
}

static int get_from_east(orientation_t orientation)
{
    if (orientation == NORTH)
        return W;
    if (orientation == EAST)
        return S;
    if (orientation == SOUTH)
        return E;
    return N;
}

static int get_from_west(orientation_t orientation)
{
    if (orientation == NORTH)
        return E;
    if (orientation == EAST)
        return N;
    if (orientation == SOUTH)
        return W;
    return S;
}

int ai_get_direction_from_orientation(ai_t *ai, orientation_t orientation)
{
    if (ai->orientation == NORTH)
        return get_from_north(orientation);
    if (ai->orientation == SOUTH)
        return get_from_south(orientation);
    if (ai->orientation == EAST)
        return get_from_east(orientation);
    return get_from_west(orientation);
}
