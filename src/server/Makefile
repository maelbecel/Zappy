##
## EPITECH PROJECT, 2023
## Zappy server
## File description:
## Makefile
##

SRC_DIR = src

BUILD_DIR = build

SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/server.c

SRC +=	$(SRC_DIR)/options/del_options.c \
		$(SRC_DIR)/options/init_options.c \
		$(SRC_DIR)/options/get_options.c \
		$(SRC_DIR)/options/options_getter/get_clients_nb.c \
		$(SRC_DIR)/options/options_getter/get_freq.c \
		$(SRC_DIR)/options/options_getter/get_height.c \
		$(SRC_DIR)/options/options_getter/get_port.c \
		$(SRC_DIR)/options/options_getter/get_teams_names.c \
		$(SRC_DIR)/options/options_getter/get_width.c

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

NAME = zappy_server

CFLAGS += -Wall -Wextra

CFLAGS += -I include -I libs/list/include -I libs/socket/include

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libs/list
	@make -C libs/socket
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) \
	&& $(ECHO) $(BOLD) $(GREEN)"► SERVER BUILD SUCCESS !"$(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED)"► SERVER BUILD FAILED"$(DEFAULT) && exit 1)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -o $@ -c $< $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] " \
	$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) \
	$(BOLD) $< | rev | cut -d'/' -f 1 | rev && $(ECHO) -n $(DEFAULT)

clean:
	rm -f $(OBJ)
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	make -C libs/list fclean
	make -C libs/socket fclean

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug

ECHO       =       /bin/echo -e
DEFAULT    =       "\033[00m"

BOLD       =       "\e[1m"
RED        =       "\e[31m"
GREEN      =       "\e[32m"
WHITE      =       "\e[1;37m"