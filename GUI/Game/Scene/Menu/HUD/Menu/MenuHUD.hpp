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
    #include "Planet.hpp"
    #include "ButtonWidget.hpp"
    #include "CrossButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "SettingsHUD.hpp"

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

            /**
             * @brief Set string
             *
             * @param str The string to set
             * @param pos The position of the string
             * @param fontSize The size of the font
             */
            sf::Text setString(std::string str, sf::Vector2f pos, size_t fontSize);

        // Attributes
        private:
            sf::RectangleShape _background;  /*!< Background of the Menu HUD */
            sf::Sprite _popUpSprite;         /*!< Pop up for the server error */
            sf::Text _popUpText;             /*!< Text of the pop up */
            InputBox _ip;                    /*!< Input box for the ip */
            InputBox _port;                  /*!< Input box for the port */
            Planet _planet;                  /*!< Planet of the Menu HUD */
            IButton *_connectButton;         /*!< Button to connect to the server */
            IButton *_settingsButton;        /*!< Button to go to the settings */
            IButton *_quitButton;            /*!< Button to quit the game */
            IButton *_crossButton;           /*!< Button to close the pop up */
            SettingsHUD _settingsHUD;        /*!< Settings HUD */
            sf::Sprite _titleHeader;         /*!< Title of the game */
            sf::Text _titleText;             /*!< Text of the title */
            bool _popUp;                     /*!< Boolean to know if the pop up is opened */
    };
};

#endif /* !MENUHUD_HPP_ */
