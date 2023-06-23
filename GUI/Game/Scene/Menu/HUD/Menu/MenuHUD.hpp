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
    #include "CrossButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "SettingsHUD.hpp"
    #include "VFX.hpp"

namespace UI {
    class MenuHUD {
        // Constructor & Destructor
        public:
            MenuHUD(std::string ip = "", std::string port = "");
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
            void handleEvent(sf::Event event, Network::Server &server, sf::RenderWindow &window);

            /**
             * @brief Initialize the Menu HUD
             *
             * @param ip The ip to connect to
             * @param port The port to connect to
             */
            void Initialize(std::string ip = "", std::string port = "");

        // Attributes
        private:
            sf::RectangleShape _background;  /*!< Background of the Menu HUD */
            InputBox _ip;                    /*!< Input box for the ip */
            InputBox _port;                  /*!< Input box for the port */
            IButton *_connectButton;         /*!< Button to connect to the server */
            IButton *_settingsButton;        /*!< Button to go to the settings */
            IButton *_quitButton;            /*!< Button to quit the game */
            SettingsHUD *_settingsHUD;        /*!< Settings HUD */
            sf::Sprite _titleHeader;         /*!< Title of the game */
            sf::Text _titleText;             /*!< Text of the title */
            Audio::VFX *_mouseClick;         /*!< Sound of the mouse click */
    };
};

#endif /* !MENUHUD_HPP_ */
