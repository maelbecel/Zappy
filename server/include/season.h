/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** season
*/

#ifndef SEASON_H_
    #define SEASON_H_

    #define TICKS_PER_SEASON 1260
    #define SEASON_CHANGING_MSG "season %d\n"

typedef enum {
    SPRING = 1,
    SUMMER = 2,
    AUTUMN = 3,
    WINTER = 4
} season_t;

#endif /* !SEASON_H_ */
