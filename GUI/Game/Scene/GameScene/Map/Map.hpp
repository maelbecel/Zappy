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

/**
 * @brief Class of the map
 */
class Map {

    // Enum
    public:
        /**
         * @brief Season enum for all season that game can have
         */
        enum Season {
            SPRING = 1,
            SUMMER = 2,
            AUTUMN = 3,
            WINTER = 4
        };

    // Constructor and Destructor (default)
    public:

        /**
         * @brief Construct a new Map object
         */
        Map();

        ~Map() = default;

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
             * @param height        The height of the tile
             * @param width         The width of the tile
             * @param gameData      The game data for map information
             * @param season        The season of the tile
             * @return sf::Sprite * The sprite of the tile
             */
            sf::Sprite *drawSeason(int height, int width, GameData &gameData, Season season);

    // Attribute
    private:
        std::map<std::string, std::shared_ptr<sf::Sprite>> _tiles; /*!< The tiles for the map */

    // Define
    public:
        static const int SEA_SIZE = 3;              /*!< The size of the sea around the map */
        static const int SEASON_DURATION = 1000000; /*!< The duration of a season */
};

inline Map::Season string_to_season(std::string season)
{
    if (season == "1")
        return Map::Season::SPRING;
    if (season == "2")
        return Map::Season::SUMMER;
    if (season == "3")
        return Map::Season::AUTUMN;
    if (season == "4")
        return Map::Season::WINTER;
    return Map::Season::SPRING;
}

inline std::string season_to_string(Map::Season season)
{
    if (season == Map::Season::SPRING)
        return "1";
    if (season == Map::Season::SUMMER)
        return "2";
    if (season == Map::Season::AUTUMN)
        return "3";
    if (season == Map::Season::WINTER)
        return "4";
    return "1";
}

#endif /* !MAP_HPP_ */
