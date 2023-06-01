/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** TIle
*/

#ifndef TILE_HPP_
    #define TILE_HPP_

    #include <SFML/Graphics.hpp>

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
        ~Tile() = default;

    // Attributes
    private:
        sf::Vector2i _coordonates;  /*!< The coordonates of the tile */
        int _quantities;            /*!< The total number of resources */
        int _q0;                    /*!< The quantity of food */
        int _q1;                    /*!< The quantity of linemate */
        int _q2;                    /*!< The quantity of deraumere */
        int _q3;                    /*!< The quantity of sibur */
        int _q4;                    /*!< The quantity of mendiane */
        int _q5;                    /*!< The quantity of phiras */
        int _q6;                    /*!< The quantity of thystame */
};

#endif /* !TILE_HPP_ */
