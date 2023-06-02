/*
** EPITECH PROJECT, 2023
** Logging lib
** File description:
** olog
*/

#ifndef OLOG_H_
    #define OLOG_H_

    #include <stdio.h>

    #define DEBUG 1

    // Add colors to the logs
    #define OLOG_COLOR_RED "\033[0;31m"
    #define OLOG_COLOR_GREEN "\033[0;32m"
    #define OLOG_COLOR_YELLOW "\033[0;33m"
    #define OLOG_COLOR_BLUE "\033[0;34m"
    #define OLOG_COLOR_MAGENTA "\033[0;35m"
    #define OLOG_COLOR_CYAN "\033[0;36m"
    #define OLOG_COLOR_RESET "\033[0m"

    #define OLOG(fmt, ...) \
        fprintf(stdout, fmt, __VA_ARGS__)

    #define OLOG_INFO(fmt, ...) \
        fprintf(stdout, OLOG_COLOR_GREEN "[INFO] " OLOG_COLOR_RESET fmt "\n", \
        __VA_ARGS__)

    #define OLOG_WARN(fmt, ...) \
        fprintf(stdout, OLOG_COLOR_YELLOW "[WARN] " OLOG_COLOR_RESET fmt "\n", \
        __VA_ARGS__)

    #define OLOG_ERROR(fmt, ...) \
        fprintf(stderr, OLOG_COLOR_RED "[ERROR] " OLOG_COLOR_RESET fmt "\n", \
        __VA_ARGS__)

    #define OLOG_FATAL(fmt, ...) \
        fprintf(stderr, OLOG_COLOR_MAGENTA "[FATAL] " fmt OLOG_COLOR_RESET \
        "\n", __VA_ARGS__)

    #define OLOG_INFOA(fmt) \
        fprintf(stdout, OLOG_COLOR_GREEN "[INFO] " OLOG_COLOR_RESET fmt "\n")

    #define OLOG_WARNA(fmt) \
        fprintf(stdout, OLOG_COLOR_YELLOW "[WARN] " OLOG_COLOR_RESET fmt "\n")

    #define OLOG_ERRORA(fmt) \
        fprintf(stderr, OLOG_COLOR_RED "[ERROR] " OLOG_COLOR_RESET fmt "\n")

    #define OLOG_FATALA(fmt) \
        fprintf(stderr, OLOG_COLOR_MAGENTA "[FATAL] " fmt OLOG_COLOR_RESET "\n")

    // Check if the debug mode is enabled
    #if DEBUG == 1
        #define OLOG_DEBUG(fmt, ...) \
            fprintf(stdout, OLOG_COLOR_MAGENTA "[DEBUG] " OLOG_COLOR_RESET fmt \
            "\n", __VA_ARGS__)

        #define OLOG_DEBUGA(fmt) \
            fprintf(stdout, OLOG_COLOR_MAGENTA "[DEBUG] " OLOG_COLOR_RESET fmt \
            "\n")
    #else
        #define OLOG_DEBUG(fmt, ...)
        #define OLOG_DEBUG(fmt)
    #endif /* DEBUG */

#endif /* !OLOG_H_ */
