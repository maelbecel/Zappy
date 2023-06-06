##
## EPITECH PROJECT, 2023
## olympe-socket-lib
## File description:
## Makefile
##
SRC =   src/create_listen_socket.c \
		src/create_socket.c \
		src/destroy_socket.c

OBJ = $(SRC:.c=.o)

NAME = libosocket.a

CFLAGS += -Wall -Wextra -Werror -W -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ) \
	&& $(ECHO) $(BOLD) $(GREEN)"► SOCKET-LIB BUILD SUCCESS !"$(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED)"► SOCKET-LIB BUILD FAILED"$(DEFAULT) && exit 1)

clean:
	@rm -f $(OBJ)
	@rm -f *~

fclean: clean
	@rm -f $(NAME)

re: fclean all

%.o:	%.c
	@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d'/' -f 1 | rev && $(ECHO) -n $(DEFAULT)

.PHONY: all clean fclean re

ECHO       =       /bin/echo -e
DEFAULT    =       "\033[00m"

BOLD       =       "\e[1m"
RED        =       "\e[31m"
GREEN      =       "\e[32m"
WHITE      =       "\e[1;37m"
