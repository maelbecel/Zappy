##
## EPITECH PROJECT, 2023
## Zappy server
## File description:
## Makefile
##

SRC_DIR = ../src

BUILD_DIR = ../build

LIBS_DIR = ../libs

SRC =	$(SRC_DIR)/inventory/inventory_create.c \
		$(SRC_DIR)/inventory/inventory_destroy.c \
		inventory.c

SRC +=	$(SRC_DIR)/ai/ai_create.c \
		$(SRC_DIR)/ai/ai_destroy.c \
		ai.c

SRC +=	$(SRC_DIR)/utils/id_generator.c \
		$(SRC_DIR)/utils/read_socket.c \
		$(SRC_DIR)/utils/ostr_to_array.c \
		utils.c

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

NAME = unit_tests

CFLAGS += -Wall -Wextra

CFLAGS += -I ../include -I $(LIBS_DIR)/list/include \
-I $(LIBS_DIR)/socket/include

LDFLAGS += -L $(LIBS_DIR)/list -lolist -L $(LIBS_DIR)/socket -losocket \
-lcriterion --coverage

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBS_DIR)/list
	@make -C $(LIBS_DIR)/socket
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) \
	&& $(ECHO) $(BOLD) $(GREEN)"► SERVER TESTS BUILD SUCCESS !"$(DEFAULT) \
	|| ($(ECHO) $(BOLD) $(RED)"► SERVER TESTS BUILD FAILED"$(DEFAULT) && exit 1)

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
	make -C $(LIBS_DIR)/list fclean
	make -C $(LIBS_DIR)/socket fclean

re: fclean all

.PHONY: all clean fclean re

ECHO       =       /bin/echo -e
DEFAULT    =       "\033[00m"

BOLD       =       "\e[1m"
RED        =       "\e[31m"
GREEN      =       "\e[32m"
WHITE      =       "\e[1;37m"
