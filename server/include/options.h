/*
** EPITECH PROJECT, 2023
** Zappy (Workspace) [WSL: Ubuntu]
** File description:
** options
*/

#ifndef OPTIONS_H_
    #define OPTIONS_H_

    #define HELP_MESSAGE "USAGE: ./zappy_server -p port -x width -y height -n \
name1 name2 ... -c clientsNb -f freq\n\
\tport is the port number\n\
\twidth is the width of the world\n\
\theight is the height of the world\n\
\tnameX is the name of the team X\n\
\tclientsNb is the number of authorized clients per team\n\
\tfreq is the reciprocal of time unit for execution of actions\n\
"

typedef unsigned int uint;

typedef struct options_s {
    unsigned short port;
    uint width;
    uint height;
    char **teams_name;
    uint clients_nb;
    uint freq;
} options_t;

typedef struct options_getter_s {
    char flag;
    int (*func)(options_t *options, char *arg);
} options_getter_t;

options_t *init_options(void);
void del_options(options_t *options);
void flag_error(int flag, char *message);
options_t *get_options(int ac, char **av);

int get_port(options_t *options, char *arg);
int get_width(options_t *options, char *arg);
int get_height(options_t *options, char *arg);
int get_clients_nb(options_t *options, char *arg);
int get_freq(options_t *options, char *arg);

int get_teams_names(options_t *options, int argc, char **argv);

#endif /* !OPTIONS_H_ */
