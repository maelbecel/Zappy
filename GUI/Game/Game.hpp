/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Game
*/

#ifndef GAME_HPP_
    #define GAME_HPP_

    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <map>

    #include "Menu.hpp"
    #include "GameScene.hpp"
    #include "Server.hpp"
    #include "FontManager.hpp"
    #include "Music.hpp"

class Game {
    // Constructor & Destructor
    public:
        Game();
        ~Game();

    // Methods
    public:

        /**
         * @brief Initialize the game
         */
        void Initialize(std::string ip = "", std::string port = "");

        /**
         * @brief Render all the game on the window given in parameter
         *
         * @param window The window where the game will be drawn
         */
        void Render(sf::RenderWindow &window);

        /**
         * @brief Update the game
         */
        void Update();

        /**
         * @brief Handle the event given in parameter
         * All the events are handled here
         * @param event  The event to handle
         */
        void OnEvent(const sf::Event &event, sf::RenderWindow &window);

    // Attributes
    private:
        std::map<std::string, std::pair<Scene::IScene *, bool>> _scenes; /*!< All the scenes */

        Network::Server _server; /*!< The server */

        Audio::Music *_ost;      /*!< The music */
};

#endif /* !GAME_HPP_ */
