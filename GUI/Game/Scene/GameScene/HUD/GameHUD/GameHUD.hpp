/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameHUD
*/

#ifndef GAMEHUD_HPP_
    #define GAMEHUD_HPP_

    #include <libconfig.h++>

    #include "ParserError.hpp"
    #include "BackgroundStyle.hpp"
    #include "InputBox.hpp"
    #include "Server.hpp"
    #include "Button.hpp"
    #include "ButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "SettingsHUD.hpp"
    #include "SFX.hpp"

namespace UI {
    class GameHUD {
        // Constructor & Destructor
        public:
            GameHUD();
            ~GameHUD() = default;

        // Methods
        public:

            /**
             * @brief Draw the Settings HUD
             *
             * @param window The window where the HUD will be drawn
             */
            void draw(sf::RenderWindow &window);

            /**
             * @brief Handle the event of the Settings HUD
             *
             * @param event  The event to handle
             * @param server The server to connect to
             */
            bool handleEvent(sf::Event event, Network::Server &server, sf::RenderWindow &window);

            /**
             * @brief Set string
             *
             * @param str
             */
            sf::Text setString(std::string str, sf::Vector2f pos);

        // Attributes
        private:
            sf::Sprite _backgroundSprite; /*!< Sprite of the Settings HUD */
            std::shared_ptr<IButton>_speed1x;            /*!< Button to resume the game */
            std::shared_ptr<IButton>_speed2x;            /*!< Button to go to the settings */
            std::shared_ptr<IButton>_speed4x;            /*!< Button to quit the game */
            sf::Text _speed1xText;        /*!< Text of the resume button */
            sf::Text _speed2xText;        /*!< Text of the settings button */
            sf::Text _speed4xText;        /*!< Text of the quit button */
            std::shared_ptr<Audio::SFX> _mouseClick;      /*!< Sound of the mouse click */
    };
};

#endif /* !GAMEHUD_HPP_ */
