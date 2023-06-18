/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** TileHUD
*/

#ifndef TILEHUD_HPP_
    #define TILEHUD_HPP_

    #include <libconfig.h++>

    #include "ParserError.hpp"
    #include "BackgroundStyle.hpp"
    #include "InputBox.hpp"
    #include "Server.hpp"
    #include "Button.hpp"
    #include "ButtonWidget.hpp"
    #include "NetworkError.hpp"
    #include "Tile.hpp"
    #include "GameData.hpp"

namespace UI {
    class TileHUD {
        // Constructor & Destructor
        public:
            TileHUD();
            ~TileHUD();

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
             * @brief Set string
             *
             * @param str The string to set
             */
            sf::Text setString(std::string str, sf::Vector2f pos);

            /**
             * @brief Set the Is Open object
             *
             * @param isOpen Boolean to know if the Tile HUD is open
             */
            void setIsOpen(bool isOpen);

            /**
             * @brief Get the Is Open object
             *
             * @return true The Tile HUD is open
             * @return false The Tile HUD is not open
             */
            bool getIsOpen() const;

            /**
             * @brief Set the HUD with the tile information
             *
             * @param gameData The game data
             * @param isLeft Boolean to know if the HUD is on the left or on the right
             * @param x The x position of the tile
             * @param y The y position of the tile
             */
            void setTileHUD(GameData &gameData, bool isLeft, int x, int y);

            /**
             * @brief Construct the content
             *
             * @param gameData The game data
             * @param x The x position of the tile
             * @param y The y position of the tile
             * @return std::string The content of the tile
             */
            std::string constructContent(GameData &gameData, int x, int y);

        // Attributes
        private:
            sf::Sprite _backgroundSprite;           /*!< Sprite of the Settings HUD */
            sf::RectangleShape _background;         /*!< Background of the Settings HUD */
            bool _isOpen;                           /*!< Is the Tile HUD open ? */
            sf::Text _tilePosition;                 /*!< Text of the tile position */
            sf::Text _tileContent;                  /*!< Text of the tile content */
            IButton *_crossTileHUDButton;          /*!< Button to close the settings */

    };
};

#endif /* !TILEHUD_HPP_ */
