##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	./Main.cpp\
		./App/Application.cpp\
		./Game/Game.cpp\
		./Game/Scene/GameScene/GameScene.cpp\
		./Game/Scene/GameScene/GameData/GameData.cpp\
		./Game/Scene/GameScene/Map/Map.cpp\
		./Game/Scene/GameScene/Tiles/Tile.cpp\
		./Game/Scene/GameScene/Player/Player.cpp\
		./Game/Scene/GameScene/HUD/TeamHUD/TeamHUD.cpp\
		./Game/Scene/Menu/Menu.cpp\
		./Game/Scene/Menu/HUD/MenuHUD.cpp\
		./Game/Scene/Menu/HUD/Widget/InputBox.cpp\
		./Game/Scene/Menu/HUD/Widget/ButtonWidget.cpp\
		./Game/Scene/Settings/Settings.cpp\
		./Game/Scene/Settings/HUD/SettingsHUD.cpp\
		./Parser/Parser.cpp\
		./Server/Server.cpp\
		./Server/Socket/Socket.cpp\

SRC	+=	./Tools/PerlinNoise.cpp\

SRC	+=	./UI/Animation/Animation.cpp\
		./UI/Button/Button.cpp\
		./UI/InputHandler/InputHandler.cpp\
		./UI/Styling/BackgroundStyle.cpp\
		./UI/Styling/BorderStyle.cpp\
		./UI/Transition/Transition.cpp\
		./UI/Manager/FontManager.cpp\
		./UI/Manager/TextureManager.cpp\
		./UI/Layout/GridLayout.cpp\
		./UI/Layout/HorizontalLayout.cpp\
		./UI/Layout/VerticalLayout.cpp\

INCLUDE =	-I .\
			-I ./App\
			-I ./Error/\
			-I ./Game/\
			-I ./Game/Scene/\
			-I ./Game/Scene/GameScene/\
			-I ./Game/Scene/GameScene/GameData/\
			-I ./Game/Scene/GameScene/Tiles/\
			-I ./Game/Scene/GameScene/Player/\
			-I ./Game/Scene/GameScene/Map/\
			-I ./Game/Scene/GameScene/HUD/TeamHUD/\
			-I ./Game/Scene/Menu/\
			-I ./Game/Scene/Menu/HUD/\
			-I ./Game/Scene/Menu/HUD/Widget/\
			-I ./Game/Scene/Settings/\
			-I ./Game/Scene/Settings/HUD/\
			-I ./Parser/\
			-I ./Server/\
			-I ./Server/Socket/\
			-I ./Tools/\
			-I ./UI/Animation/\
			-I ./UI/Button/\
			-I ./UI/EventHandler/\
			-I ./UI/InputHandler/\
			-I ./UI/Styling/\
			-I ./UI/Transition/\
			-I ./UI/Widget/\
			-I ./UI/Manager/\
			-I ./UI/Layout/\

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