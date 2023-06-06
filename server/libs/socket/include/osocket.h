/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** osocket
*/

#ifndef OSOCKET_H_
    #define OSOCKET_H_

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <stddef.h>

typedef struct socket_s {
    int fd;
    int port;
    struct sockaddr_in addr;
} socket_t;

socket_t *ocreate_socket(void);
socket_t *ocreate_socket_with_fd(int fd);
socket_t *ocreate_empty_socket(void);
void odestroy_socket(socket_t *socket);

socket_t *ocreate_listen_socket(int port, int queue);

#endif /* !OSOCKET_H_ */
