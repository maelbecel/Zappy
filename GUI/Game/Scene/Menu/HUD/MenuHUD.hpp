/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** MenuHUD
*/

#ifndef MENUHUD_HPP_
    #define MENUHUD_HPP_

    #include "BackgroundStyle.hpp"
    #include "InputBox.hpp"
    #include "Server.hpp"
    #include "Button.hpp"
    #include "ButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "Settings.hpp"

namespace UI {
    class MenuHUD {
        // Constructor & Destructor
        public:
            MenuHUD();
            ~MenuHUD();

        // Methods
        public:

            /**
             * @brief Draw the Menu HUD
             *
             * @param window The window where the HUD will be drawn
             */
            void draw(sf::RenderWindow &window);

            /**
             * @brief Handle the event of the Menu HUD
             *
             * @param event  The event to handle
             * @param server The server to connect to
             */
            void handleEvent(sf::Event event, Network::Server &server);

        // Attributes
        private:
            sf::RectangleShape _background;  /*!< Background of the Menu HUD */
            InputBox _ip;                    /*!< Input box for the ip */
            InputBox _port;                  /*!< Input box for the port */
            IButton *_connectButton;               /*!< Button to connect to the server */
            IButton *_settingsButton;              /*!< Button to go to the settings */
            IButton *_quitButton;                  /*!< Button to quit the game */
            bool _settingsButtonOpen;              /*!< Boolean to know if the settings are open */
            Scene::Settings _settings;                    /*!< Settings scene */
            IButton *_crossSettingsButton;                /*!< Button to close the settings */
            sf::Sprite _titleHeader;                            /*!< Title of the game */
            sf::Text _titleText;                                /*!< Text of the title */
    };
};

#endif /* !MENUHUD_HPP_ */