/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** GameMenuHUD
*/

#ifndef GAMEMENUHUD_HPP_
    #define GAMEMENUHUD_HPP_

    #include <libconfig.h++>

    #include "ParserError.hpp"
    #include "BackgroundStyle.hpp"
    #include "InputBox.hpp"
    #include "Server.hpp"
    #include "Button.hpp"
    #include "ButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "SettingsHUD.hpp"

namespace UI {
    class GameMenuHUD {
        // Constructor & Destructor
        public:
            GameMenuHUD();
            ~GameMenuHUD();

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
            void handleEvent(sf::Event event, Network::Server &server, sf::RenderWindow &window);

            /**
             * @brief Check if the Settings HUD is opened
             */
            bool isOpened() const;

            /**
             * @brief Set the Settings HUD opened or not
             */
            void setOpened(bool opened);

        // Attributes
        private:
            sf::RectangleShape _background;         /*!< Background of the Settings HUD */
            sf::Sprite _backgroundSprite;           /*!< Sprite of the Settings HUD */
            IButton *_resumeButton;                 /*!< Button to resume the game */
            IButton *_settingsButton;              /*!< Button to go to the settings */
            IButton *_quitButton;                  /*!< Button to quit the game */
            SettingsHUD _settingsHUD;               /*!< Settings HUD */
            bool _isOpened;                         /*!< Is the Settings HUD opened */
    };
};

#endif /* !GAMEMENUHHPP_ */
