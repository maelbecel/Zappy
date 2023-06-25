/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** HelpHUD
*/

#ifndef HELPHUD_HPP_
    #define HELPHUD_HPP_

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
    class HelpHUD {
        // Constructor & Destructor
        public:
            HelpHUD();
            ~HelpHUD() = default;

        // Methods
        public:

            /**
             * @brief Draw the Help HUD
             *
             * @param window The window where the HUD will be drawn
             */
            void draw(sf::RenderWindow &window);

            /**
             * @brief Handle the event of the Help HUD
             *
             * @param event  The event to handle
             * @param server The server to connect to
             */
            void handleEvent(sf::Event event, Network::Server &server, sf::RenderWindow &window);

            /**
             * @brief Set string
             *
             * @param str
             */
            sf::Text setString(std::string str, sf::Vector2f pos, int fontSize = 10);

            /**
             * @brief Check if the Help HUD is opened
             */
            bool isOpened() const;

            /**
             * @brief Set the Help HUD opened or not
             */
            void setOpened(bool opened);

            /**
             * @brief Update the Help HUD
             *
             */
            void setLanguage();

        // Attributes
        private:
            sf::RectangleShape _background;         /*!< Background of the Tile HUD */
            sf::Sprite _backgroundSprite;           /*!< Sprite of the Help HUD */
            std::shared_ptr<IButton>_leftButton;    /*!< Button to turn left the pages */
            std::shared_ptr<IButton> _rightButton;  /*!< Button to turn right the pages */
            std::shared_ptr<IButton> _closeButton;  /*!< Button to close the Help HUD */
            sf::Text _title;                        /*!< Title of the Help HUD */
            std::map<int, std::map<int, sf::Text>> _text; /*!< Text of the Help HUD */
            int _nbrPage;                           /*!< Number of pages */
            bool _opened;                           /*!< If the Help HUD is opened or not */
            std::string _language;                  /*!< Language of the Help HUD */
    };
};

#endif /* !HELPHUD_HPP_ */
