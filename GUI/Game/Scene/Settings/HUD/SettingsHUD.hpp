/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** SettingsHUD
*/

#ifndef SETTINGSHUD_HPP_
    #define SETTINGSHUD_HPP_

    #include "BackgroundStyle.hpp"
    #include "InputBox.hpp"
    #include "Server.hpp"
    #include "Button.hpp"
    #include "ButtonWidget.hpp"
    #include "NetworkError.hpp"

namespace UI {
    class SettingsHUD {
        // Constructor & Destructor
        public:
            SettingsHUD();
            ~SettingsHUD();

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
            void handleEvent(sf::Event event, Network::Server &server);

        // Attributes
        private:
            sf::RectangleShape _background;         /*!< Background of the Settings HUD */
            InputBox _ip;                           /*!< Input box for the ip */
            InputBox _port;                         /*!< Input box for the port */
            IButton *_connectButton;                /*!< Button to connect to the server */
            IButton *_settingsButton;               /*!< Button to go to the settings */
            IButton *_quitButton;                   /*!< Button to quit the game */
    };
};

#endif /* !SETTINGSHUD_HPP_ */
