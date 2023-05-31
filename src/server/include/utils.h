/*
** EPITECH PROJECT, 2023
** Zappy [WSL: Ubuntu]
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_

    #include "client.h"

typedef unsigned long ulong;

ulong generate_id(void);
void read_socket(client_t *client);

#endif /* !UTILS_H_ */
