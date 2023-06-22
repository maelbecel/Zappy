##
## EPITECH PROJECT, 2023
## Zappy server
## File description:
## Makefile
##

SRC_DIR = src

BUILD_DIR = build

TESTS_DIR = tests

SRC =	$(SRC_DIR)/server/server_create.c \
		$(SRC_DIR)/server/server_destroy.c

SRC +=	$(SRC_DIR)/options/del_options.c \
		$(SRC_DIR)/options/init_options.c

SRC +=	$(SRC_DIR)/inventory/inventory_create.c \
		$(SRC_DIR)/inventory/inventory_destroy.c \
		$(SRC_DIR)/inventory/inventory_get_item_by_name.c

SRC += 	$(SRC_DIR)/map/tile/tile_add_player.c \
		$(SRC_DIR)/map/tile/tile_create.c \
		$(SRC_DIR)/map/tile/tile_destroy.c \
		$(SRC_DIR)/map/tile/tile_remove_player.c \
		$(SRC_DIR)/map/tile/tile_get_players.c \
		$(SRC_DIR)/map/map_create.c \
		$(SRC_DIR)/map/map_destroy.c \
		$(SRC_DIR)/map/map_get_tile.c \
		$(SRC_DIR)/map/map_spawn_items.c

SRC +=	$(SRC_DIR)/client/client_accept.c \
		$(SRC_DIR)/client/client_create.c \
		$(SRC_DIR)/client/client_destroy.c \
		$(SRC_DIR)/client/client_read.c \
		$(SRC_DIR)/client/client_disconnect.c \
		$(SRC_DIR)/client/client_get_by_id.c \
		$(SRC_DIR)/client/client_except.c \
		$(SRC_DIR)/client/write_buffer/wbuffer_add_message.c \
		$(SRC_DIR)/client/write_buffer/wbuffer_empty.c \
		$(SRC_DIR)/client/write_buffer/wbuffer_print.c

SRC +=	$(SRC_DIR)/command/command_exec.c \
		$(SRC_DIR)/command/command_exec_ai.c \
		$(SRC_DIR)/command/none/select_team.c

SRC +=	$(SRC_DIR)/utils/id_generator.c \
		$(SRC_DIR)/utils/read_socket.c \
		$(SRC_DIR)/utils/ostr_to_array.c \
		$(SRC_DIR)/utils/array_size.c \
		$(SRC_DIR)/utils/stringbuilder.c

SRC +=	$(SRC_DIR)/team/team_create.c \
		$(SRC_DIR)/team/team_destroy.c \
		$(SRC_DIR)/team/team_get_by_id.c \
		$(SRC_DIR)/team/team_get_by_name.c

SRC +=	$(SRC_DIR)/ai/ai_create.c \
		$(SRC_DIR)/ai/ai_destroy.c \
		$(SRC_DIR)/ai/ai_dead.c \
		$(SRC_DIR)/ai/ai_get_direction_from_orientation.c

SRC +=	$(SRC_DIR)/time/time_create.c \
		$(SRC_DIR)/time/time_destroy.c \
		$(SRC_DIR)/time/time_update.c

SRC +=	$(SRC_DIR)/action/action_update.c \
		$(SRC_DIR)/action/action_create.c \
		$(SRC_DIR)/action/action_destroy.c

SRC +=	$(SRC_DIR)/command/graphic/msz.c \
		$(SRC_DIR)/command/graphic/bct.c \
		$(SRC_DIR)/command/graphic/mct.c \
		$(SRC_DIR)/command/graphic/tna.c \
		$(SRC_DIR)/command/graphic/sgt.c \
		$(SRC_DIR)/command/graphic/sst.c \
		$(SRC_DIR)/command/graphic/welcome_message.c \
		$(SRC_DIR)/command/graphic/ppo.c \
		$(SRC_DIR)/command/graphic/pnw.c \
		$(SRC_DIR)/command/graphic/plv.c \
		$(SRC_DIR)/command/graphic/pin.c \
		$(SRC_DIR)/command/graphic/pgt.c \
		$(SRC_DIR)/command/graphic/pdr.c \
		$(SRC_DIR)/command/graphic/ebo.c \
		$(SRC_DIR)/command/graphic/pfk.c \
		$(SRC_DIR)/command/graphic/enw.c \
		$(SRC_DIR)/command/graphic/pex.c \
		$(SRC_DIR)/command/graphic/edi.c \
		$(SRC_DIR)/command/graphic/pic.c \
		$(SRC_DIR)/command/graphic/pie.c

SRC +=	$(SRC_DIR)/command/ai/forward.c \
		$(SRC_DIR)/command/ai/right.c \
		$(SRC_DIR)/command/ai/left.c \
		$(SRC_DIR)/command/ai/inventory.c \
		$(SRC_DIR)/command/ai/take.c \
		$(SRC_DIR)/command/ai/set.c \
		$(SRC_DIR)/command/ai/connect_nbr.c \
		$(SRC_DIR)/command/ai/look.c \
		$(SRC_DIR)/command/ai/look_func.c \
		$(SRC_DIR)/command/ai/fork.c \
		$(SRC_DIR)/command/ai/eject.c \
		$(SRC_DIR)/command/ai/eject_eggs.c \
		$(SRC_DIR)/command/ai/incantation.c \
		$(SRC_DIR)/command/ai/incantation_utils.c \
		$(SRC_DIR)/command/ai/broadcast.c \
		$(SRC_DIR)/command/ai/notif_graphic.c \
		$(SRC_DIR)/command/ai/notif_ai.c

SRC +=	$(SRC_DIR)/egg/egg_create.c \
		$(SRC_DIR)/egg/egg_destroy.c \
		$(SRC_DIR)/egg/egg_get_one_in_team.c \
		$(SRC_DIR)/egg/egg_is_egg_in_team.c \
		$(SRC_DIR)/egg/egg_add_to_team.c

MAIN += 	$(SRC_DIR)/main.c \
			$(SRC_DIR)/server.c \
			$(SRC_DIR)/main_loop.c \
			$(SRC_DIR)/sigint_handler.c \
			$(SRC_DIR)/winning_detection.c \
			$(SRC_DIR)/options/get_options.c \
			$(SRC_DIR)/options/options_getter/get_clients_nb.c \
			$(SRC_DIR)/options/options_getter/get_freq.c \
			$(SRC_DIR)/options/options_getter/get_height.c \
			$(SRC_DIR)/options/options_getter/get_port.c \
			$(SRC_DIR)/options/options_getter/get_teams_names.c \
			$(SRC_DIR)/options/options_getter/get_width.c

TESTS_SRC += 	$(TESTS_DIR)/server/test_server.c \
				$(TESTS_DIR)/time/test_time.c \
				$(TESTS_DIR)/team/test_team.c \
				$(TESTS_DIR)/egg/test_egg.c \
				$(TESTS_DIR)/map/test_tile.c \
				$(TESTS_DIR)/map/test_map.c \
				$(TESTS_DIR)/action/test_action.c \
				$(TESTS_DIR)/ai/test_ai.c \
				$(TESTS_DIR)/client/test_wbuffer.c \
				$(TESTS_DIR)/client/test_client.c \
				$(TESTS_DIR)/inventory/test_inventory.c \
			 	$(TESTS_DIR)/command/graphic/test_simple_command.c \
			 	$(TESTS_DIR)/command/ai/test_simple_command.c \
			 	$(TESTS_DIR)/command/ai/test_broadcast.c \
			 	$(TESTS_DIR)/utils/test_stringbuilder.c \
				$(TESTS_DIR)/utils/test_array_size.c \
				$(TESTS_DIR)/utils/test_ostr_to_array.c


OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
MAIN_OBJ = $(MAIN:%.c=$(BUILD_DIR)/%.o)

TESTS_OBJ = $(TESTS_SRC:%.c=$(BUILD_DIR)/%.o)

NAME = zappy_server

CFLAGS += -Wall -Wextra -D _GNU_SOURCE

CFLAGS += -I include -I libs/list/include -I libs/socket/include

LDFLAGS += -L libs/list -lolist -L libs/socket -losocket

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	@make -C libs/list
	@make -C libs/socket
	@$(CC) -o $(NAME) $(OBJ) $(MAIN_OBJ) $(CFLAGS) $(LDFLAGS) \
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
	rm -f unit_tests

re: fclean all

debug: CFLAGS += -g -D DEBUG
debug: re

tests_run: CFLAGS += --coverage
tests_run: LDFLAGS += -lcriterion
tests_run: $(OBJ) $(TESTS_OBJ)
	@make -C libs/list
	@make -C libs/socket
	@$(CC) -o unit_tests $(TESTS_OBJ) $(OBJ) $(CFLAGS) $(LDFLAGS) \
	&& $(ECHO) $(BOLD) $(GREEN)"► TESTS BUILD SUCCESS !"$(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED)"► TESTS BUILD FAILED"$(DEFAULT) && exit 1)
	@./unit_tests

.PHONY: all clean fclean re debug

ECHO       =       /bin/echo -e
DEFAULT    =       "\033[00m"

BOLD       =       "\e[1m"
RED        =       "\e[31m"
GREEN      =       "\e[32m"
WHITE      =       "\e[1;37m"
