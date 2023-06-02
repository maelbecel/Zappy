/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

    #include "GameData.hpp"

class Map {
    // Constructor and Destructor (default)
    public:
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

    // Attributes
    private:
        sf::Sprite *_sea; /*!< The sea Tiles for the map */

    // Define
    public:
        static const int SEA_SIZE = 3; /*!< The size of the sea around the map */
};

#endif /* !MAP_HPP_ */
