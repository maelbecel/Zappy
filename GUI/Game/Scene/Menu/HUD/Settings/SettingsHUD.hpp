/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** SettingsHUD
*/

#ifndef SETTINGSHUD_HPP_
    #define SETTINGSHUD_HPP_

    #include <libconfig.h++>

    #include "ParserError.hpp"
    #include "BackgroundStyle.hpp"
    #include "InputBox.hpp"
    #include "Server.hpp"
    #include "Button.hpp"
    #include "ButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "Window.hpp"
    #include "ArrowButtonWidget.hpp"
    #include "CrossButtonWidget.hpp"
    #include "ValidateButtonWidget.hpp"
    #include "VFX.hpp"

namespace UI {
    class SettingsHUD {
        // Constructor & Destructor
        public:
            SettingsHUD(bool isGameMenu = false);
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
             * @brief Set string
             *
             * @param string The string to set
             * @param pos The position of the string
             */
            sf::Text setString(std::string string, sf::Vector2f pos);

            /**
             * @brief Get tile HUD text mode
             *
             * @return true if the tile HUD is in text mode
             */
            bool getTileHUDTextMode() const;

            /**
             * @brief Save the settings
             */
            void saveSettings();

        // Attributes
        private:
            sf::RectangleShape _background;         /*!< Background of the Settings HUD */
            sf::Sprite _backgroundSprite;           /*!< Sprite of the Settings HUD */
            IButton *_decreaseSoundButton;          /*!< Button to decrease the sound */
            IButton *_increaseSoundButton;          /*!< Button to increase the sound */
            IButton *_decreaseMusicButton;          /*!< Button to decrease the music */
            IButton *_increaseMusicButton;          /*!< Button to increase the music */
            IButton *_changeLanguageLeftButton;  /*!< Button to change the language to the left */
            IButton *_changeLanguageRightButton; /*!< Button to change the language to the right */
            IButton *_changeTileHUDLeftButton;      /*!< Button to change the tile HUD to the left */
            IButton *_changeTileHUDRightButton;     /*!< Button to change the tile HUD to the right */
            IButton *_crossSettingsButton;          /*!< Button to close the settings */
            IButton *_validateButton;               /*!< Button to validate the settings */
            InputBox _sound;                        /*!< Input box for the sound */
            InputBox _music;                        /*!< Input box for the music */
            int _soundValue;                        /*!< Value of the sound */
            int _musicValue;                        /*!< Value of the music */
            sf::Text _tileHUDTextMode;              /*!< Is the tile HUD in text mode */
            sf::Text _languageText;                 /*!< Language text */
            bool _isOpened;                         /*!< Is the Settings HUD opened */
            bool _isGameMenu;                       /*!< Is the Game Menu HUD opened */
            Audio::VFX *_mouseClick;                /*!< Mouse click sound */
    };
};

#endif /* !SETTINGSHUD_HPP_ */
