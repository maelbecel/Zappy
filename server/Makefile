##
## EPITECH PROJECT, 2023
## Zappy server
## File description:
## Makefile
##

SRC_DIR = src

BUILD_DIR = build

SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/server.c \
		$(SRC_DIR)/main_loop.c

SRC +=	$(SRC_DIR)/server/server_create.c \
		$(SRC_DIR)/server/server_destroy.c

SRC +=	$(SRC_DIR)/options/del_options.c \
		$(SRC_DIR)/options/init_options.c \
		$(SRC_DIR)/options/get_options.c \
		$(SRC_DIR)/options/options_getter/get_clients_nb.c \
		$(SRC_DIR)/options/options_getter/get_freq.c \
		$(SRC_DIR)/options/options_getter/get_height.c \
		$(SRC_DIR)/options/options_getter/get_port.c \
		$(SRC_DIR)/options/options_getter/get_teams_names.c \
		$(SRC_DIR)/options/options_getter/get_width.c

SRC +=	$(SRC_DIR)/inventory/inventory_create.c \
		$(SRC_DIR)/inventory/inventory_destroy.c

SRC += 	$(SRC_DIR)/map/tile/tile_add_player.c \
		$(SRC_DIR)/map/tile/tile_create.c \
		$(SRC_DIR)/map/tile/tile_destroy.c \
		$(SRC_DIR)/map/tile/tile_remove_player.c \
		$(SRC_DIR)/map/map_create.c \
		$(SRC_DIR)/map/map_destroy.c \
		$(SRC_DIR)/map/map_get_tile.c

SRC +=	$(SRC_DIR)/client/client_accept.c \
		$(SRC_DIR)/client/client_create.c \
		$(SRC_DIR)/client/client_destroy.c \
		$(SRC_DIR)/client/client_read.c \
		$(SRC_DIR)/client/client_disconnect.c \

SRC +=	$(SRC_DIR)/command/command_exec.c \
		$(SRC_DIR)/command/command_exec_ai.c \
		$(SRC_DIR)/command/none/select_team.c

SRC +=	$(SRC_DIR)/utils/id_generator.c \
		$(SRC_DIR)/utils/read_socket.c \
		$(SRC_DIR)/utils/ostr_to_array.c

SRC +=	$(SRC_DIR)/team/team_create.c \
		$(SRC_DIR)/team/team_destroy.c

SRC +=	$(SRC_DIR)/ai/ai_create.c \
		$(SRC_DIR)/ai/ai_destroy.c

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

NAME = zappy_server

CFLAGS += -Wall -Wextra

CFLAGS += -I include -I libs/list/include -I libs/socket/include

LDFLAGS += -L libs/list -lolist -L libs/socket -losocket

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libs/list
	@make -C libs/socket
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) \
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
