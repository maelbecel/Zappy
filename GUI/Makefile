##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	./Main.cpp\
		./App/Application.cpp\
		./Game/Game.cpp\
		./Game/Scene/GameScene.cpp\
		./Game/Scene/Menu/Menu.cpp\
		./Game/Scene/Menu/HUD/MenuHUD.cpp\
		./Game/Scene/Menu/HUD/Widget/InputBox.cpp\
		./Game/Scene/Menu/HUD/Widget/ButtonWidget.cpp\
		./Parser/Parser.cpp\
		./Server/Server.cpp\
		./Server/Socket/Socket.cpp\

SRC	+=	./UI/Animation/Animation.cpp\
		./UI/Button/Button.cpp\
		./UI/InputHandler/InputHandler.cpp\
		./UI/Styling/BackgroundStyle.cpp\
		./UI/Styling/BorderStyle.cpp\
		./UI/Transition/Transition.cpp\
		./UI/Manager/FontManager.cpp\
		./UI/Manager/TextureManager.cpp\
		#./UI/Layout/GridLayout.cpp\
		./UI/Layout/HorizontalLayout.cpp\
		./UI/Layout/VerticalLayout.cpp\

INCLUDE =	-I .\
			-I ./App\
			-I ./Error/\
			-I ./Game/\
			-I ./Game/Scene/\
			-I ./Game/Scene/Menu/\
			-I ./Game/Scene/Menu/HUD/\
			-I ./Game/Scene/Menu/HUD/Widget/\
			-I ./Parser/\
			-I ./Server/\
			-I ./Server/Socket/\
			-I ./UI/Animation/\
			-I ./UI/Button/\
			-I ./UI/EventHandler/\
			-I ./UI/InputHandler/\
			-I ./UI/Styling/\
			-I ./UI/Transition/\
			-I ./UI/Widget/\
			-I ./UI/Manager/\
			#-I ./UI/Layout/\

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_gui

CXXFLAGS += -std=c++20 -Wall -Wextra

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all:	$(NAME)

%.o: %.cpp
	g++ $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(INCLUDE) $(SFML)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

debug: CXXFLAGS += -g
debug: fclean $(NAME)

.PHONY: all clean fclean re debug