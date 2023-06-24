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
    #include "SFX.hpp"
    #include "HelpHUD.hpp"

namespace UI {
    class GameMenuHUD {

        // Constructor & Destructor
        public:
            GameMenuHUD();

            ~GameMenuHUD() = default;

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

            /**
             * @brief Get tile dislpay mode
             *
             */
            bool getTileDisplayMode() const;

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
            sf::RectangleShape _background;         /*!< Background of the Settings HUD */
            std::shared_ptr<IButton> _resumeButton;                 /*!< Button to resume the game */
            std::shared_ptr<IButton> _settingsButton;              /*!< Button to go to the settings */
            std::shared_ptr<IButton> _helpButton;                  /*!< Button to go to the help */
            std::shared_ptr<IButton> _quitButton;                  /*!< Button to quit the game */
            std::shared_ptr<SettingsHUD> _settingsHUD;               /*!< Settings HUD */
            HelpHUD _helpHUD;                       /*!< Help HUD */
            bool _isOpened;                         /*!< Is the Settings HUD opened */
            std::shared_ptr<Audio::SFX> _mouseClick;                /*!< Mouse click sound */
            std::string _language;           /*!< Language of the game */
    };
};

#endif /* !GAMEMENUHHPP_ */
