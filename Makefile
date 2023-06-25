##
## EPITECH PROJECT, 2023
## Zappy
## File description:
## Makefile
##

all: server ai ui

server:
	@make -C server/
	@mv server/zappy_server .

ai:
	echo "ai"
	@cp clientAi/zappy_ai .
	@cp clientAi/zappy_ai2 .
	@cp clientAi/zappy_ai3 .

ui:
	@make -C GUI
	@cp -r GUI/Assets .
	@cp -r GUI/Config .
	@mv GUI/zappy_gui .

fclean:
	@make fclean -C server/
	@make fclean -C GUI/
	@rm -f zappy_server zappy_ai zappy_ai2 zappy_ai3 zappy_gui
	@rm -rf Assets Config