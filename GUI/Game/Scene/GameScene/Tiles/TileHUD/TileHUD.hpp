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
             * @param tile The tile to get the information from
             * @param isLeft Boolean to know if the HUD is on the left or on the right
             */
            void setTileHUD(std::shared_ptr<Tile> tile, bool isLeft);

        // Attributes
        private:
            sf::Sprite _backgroundSprite;           /*!< Sprite of the Settings HUD */
            sf::RectangleShape _background;         /*!< Background of the Settings HUD */
            bool _isOpen;                           /*!< Is the Tile HUD open ? */
    };
};

#endif /* !TILEHUD_HPP_ */
