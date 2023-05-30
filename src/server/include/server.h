/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #include <stdbool.h>
    #include "options.h"
    #include "olist.h"

    #ifndef NULL
        #define NULL (0)
    #endif

    #ifndef EXIT_SUCCESS
        #define EXIT_SUCCESS 0
    #endif

    #define UNUSED __attribute__((unused))
    #define EXIT_FAILTEK 84

typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef signed long long llong;
typedef unsigned long long ullong;

typedef struct server_s {
    bool running;
    olist_t *clients;
} server_t;

#endif /* !SERVER_H_ */
