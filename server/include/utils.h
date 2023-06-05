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
typedef unsigned int uint;

ulong generate_id(void);
void read_socket(client_t *client);
char **ostr_to_array(char *str, char *separators);
uint array_size(char **array);

#endif /* !UTILS_H_ */
