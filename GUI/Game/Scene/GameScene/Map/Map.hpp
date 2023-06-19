/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include "GameData.hpp"
    #include "PerlinNoise.hpp"
    #include "TextureManager.hpp"
    #include "TextureError.hpp"

class Map {
    public:
        enum Season {
            SUMMER,
            EARLY_WINTER,
            WINTER,
            LATE_WINTER
        };

    // Constructor and Destructor (default)
    public:
        Map();
        ~Map();

    // Methods
    public:

            /**
            * @brief Draw the map in Isometric
            * @param window   The window where to draw
            * @param gameData The game data for map information
            */
            void draw(sf::RenderWindow &window, GameData &gameData);
            void drawBiome(sf::RenderWindow &window, GameData &gameData);

            /**
             * @brief Get a sprite of a tile refer to his season
             *
             * @param height       The height of the tile
             * @param width        The width of the tile
             * @param gameData     The game data for map information
             * @return sf::Sprite* The sprite of the tile
             */
            sf::Sprite *drawSummer(int height, int width, GameData &gameData);
            sf::Sprite *drawWinter(int height, int width, GameData &gameData);

    // Attributes
    private:
        std::map<std::string, sf::Sprite *> _tiles; /*!< The tiles for the map */
        Season _season;                             /*!< The season of the map */

    // Define
    public:
        static const int SEA_SIZE = 3;              /*!< The size of the sea around the map */
        static const int SEASON_DURATION = 1000000; /*!< The duration of a season */
};

#endif /* !MAP_HPP_ */
