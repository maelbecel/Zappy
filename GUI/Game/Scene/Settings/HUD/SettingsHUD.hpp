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
            IButton *_decreaseSoundButton;          /*!< Button to decrease the sound */
            IButton *_increaseSoundButton;          /*!< Button to increase the sound */
            IButton *_decreaseMusicButton;          /*!< Button to decrease the music */
            IButton *_increaseMusicButton;          /*!< Button to increase the music */
            IButton *_crossSettingsButton;          /*!< Button to close the settings */
            InputBox _sound;                        /*!< Input box for the sound */
            InputBox _music;                        /*!< Input box for the music */
            int _soundValue;                        /*!< Value of the sound */
            int _musicValue;                        /*!< Value of the music */
            bool _isOpened;                         /*!< Is the Settings HUD opened */
    };
};

#endif /* !SETTINGSHUD_HPP_ */
