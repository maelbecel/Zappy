/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** TIle
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <string>
    #include <map>

    #include "TextureError.hpp"
    #include "TextureManager.hpp"

class Tile {
    // Constructor and Destructor (default)
    public:

        /**
         * @brief Constructor of Tile
         * @param coordonates The coordonates of the tile
         * @param q0 The quantity of food
         * @param q1 The quantity of linemate
         * @param q2 The quantity of deraumere
         * @param q3 The quantity of sibur
         * @param q4 The quantity of mendiane
         * @param q5 The quantity of phiras
         * @param q6 The quantity of thystame
         */
        Tile(sf::Vector2i coordonates = sf::Vector2i(0, 0), int q0 = 0, int q1 = 0, int q2 = 0, int q3 = 0, int q4 = 0, int q5 = 0, int q6 = 0);
        ~Tile();
    
    // Getters and Setters
    public:

        /**
         * @brief Set the Position object
         * 
         * @param position The position of the tile
         */
        void setPosition(sf::Vector2f &position);

        /**
         * @brief Get the Position object
         * 
         * @return sf::Vector2f The position of the tile
         */
        sf::Vector2f getPosition() const;

        /**
         * @brief Set the New Resources object
         * 
         * @param q0 The quantity of food
         * @param q1 The quantity of linemate
         * @param q2 The quantity of deraumere
         * @param q3 The quantity of sibur
         * @param q4 The quantity of mendiane
         * @param q5 The quantity of phiras
         * @param q6 The quantity of thystame
         */
        void setNewResources(int q0, int q1, int q2, int q3, int q4, int q5, int q6);

    // Methods
    public:

        /**
         * @brief Draw the tile resources
         *
         * @param window The window where the tile will be draw
         * @param scale  The scale of the window
         */
        void draw(sf::RenderWindow &window, sf::Vector2f scale);

    // Private Methods
    private:

        /**
         * @brief Set the Tile Scale object
         *
         * @param scale         The scale of the tile
         * @return sf::Vector2f The correct scale of the tile
         */
        sf::Vector2f setTileScale(sf::Vector2f &scale);

    // Attributes
    private:
        sf::Vector2i _coordonates;                     /*!< The coordonates of the tile */
        sf::Vector2f _position;                        /*!< The position of the tile */
        int _quantities;                               /*!< The total number of resources */
        int _q0;                                       /*!< The quantity of food */
        int _q1;                                       /*!< The quantity of linemate */
        int _q2;                                       /*!< The quantity of deraumere */
        int _q3;                                       /*!< The quantity of sibur */
        int _q4;                                       /*!< The quantity of mendiane */
        int _q5;                                       /*!< The quantity of phiras */
        int _q6;                                       /*!< The quantity of thystame */

    // Define
    public:
        static const int TILE_WIDTH = 32;              /*!< Width of a tiles in pixel */
        static const int TILE_HEIGHT = 28;             /*!< Height of a tiles in pixel */
        static const int TILE_TOTAL_HEIGHT = 30;       /*!< Height of a tiles in pixel with is 3D base */
        static const int RESOURCE_WIDTH = 84;          /*!< Width of a resource in pixel */
        static const int RESOURCE_HEIGHT = 80;         /*!< Height of a resource in pixel */
        float RESOURCE_SCALE = 0.20f;                  /*!< Scale of a resource */

    // Resource Sprite
    private:
        std::map<std::string, sf::Sprite *> _resources; /*!< The resources of the tile */
};

#endif /* !TILE_HPP_ */
