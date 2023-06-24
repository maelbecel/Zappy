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
    #include "Asteroid.hpp"
    #include "ButtonWidget.hpp"
    #include "CrossButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "SettingsHUD.hpp"
    #include "SFX.hpp"

    #include <memory>

namespace UI {

    /**
     * @brief Menu HUD
     */
    class MenuHUD {

        // Constructor & Destructor (default)
        public:

            /**
             * @brief Construct a new Menu H U D object
             *
             * @param ip   The ip to connect to
             * @param port The port to connect to
             */
            MenuHUD(std::string ip = "", std::string port = "");

            ~MenuHUD() = default;

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

        // Setters
        public:

            /**
             * @brief Set string
             *
             * @param str The string to set
             * @param pos The position of the string
             * @param fontSize The size of the font
             */
            sf::Text setString(std::string str, sf::Vector2f pos, size_t fontSize);

            /**
             * @brief Set the language of the Menu HUD
             *
             */
            void setLanguage();

            /**
             * @brief Set buttons with default text
             *
             */
            void setButtonsDefault();

            /**
             * @brief Set buttons with text
             *
             */
            void setButtons(libconfig::Setting &button);

        // Attributes
        private:
            sf::RectangleShape _background;            /*!< Background of the Menu HUD */
            sf::Sprite _popUpSprite;                   /*!< Pop up for the server error */
            sf::Sprite _titleHeader;                   /*!< Title of the game */
            sf::Text _titleText;                       /*!< Text of the title */
            sf::Text _popUpText;                       /*!< Text of the pop up */
            InputBox _ip;                              /*!< Input box for the ip */
            InputBox _port;                            /*!< Input box for the port */
            std::shared_ptr<IButton> _connectButton;   /*!< Button to connect to the server */
            std::shared_ptr<IButton> _settingsButton;  /*!< Button to go to the settings */
            std::shared_ptr<IButton> _quitButton;      /*!< Button to quit the game */
            std::shared_ptr<IButton> _crossButton;     /*!< Button to close the pop up */
            std::shared_ptr<SettingsHUD> _settingsHUD; /*!< Settings HUD */
            std::shared_ptr<Audio::SFX> _mouseClick;   /*!< Sound of the mouse click */
            AsteroidHandler _asteroid;                 /*!< Asteroid of the Menu HUD */
            Planet _planet;                            /*!< Planet of the Menu HUD */
            bool _popUp;                               /*!< Boolean to know if the pop up is opened */
            bool _changePlanet;                        /*!< Boolean to know if the planet is changing */
            std::string _language;                     /*!< Language of the game */
    };
};

#endif /* !MENUHUD_HPP_ */
