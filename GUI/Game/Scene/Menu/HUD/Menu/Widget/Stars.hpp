/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Planet
*/

#ifndef STARS_HPP_
    #define STARS_HPP_

    #include "AWidget.hpp"
    #include "BorderStyle.hpp"
    #include "BackgroundStyle.hpp"

    #include <string>
    #include <iostream>

    #define RANDOM(min, max) ((float)rand() / (float)RAND_MAX * (max - min) + min)

namespace UI {

    /**
     * @brief Star class
     * Use for animated the background of the menu
     */
    class Star {

        // Constructor & Destructor (default)
        public:
            
            /**
             * @brief Construct a new Star object
             *
             * @param pos       The position of the star
             * @param intensity The intensity of the star
             * @param size      The size of the star
             */
            Star(const sf::Vector2f &pos, float intensity, int size) : pos(pos), intensity(intensity), size(size) {};

            /**
             * @brief Construct a new Star object
             *
             * @param x The x position of the star
             * @param y The y position of the star
             */
            Star(int x, int y) : pos(sf::Vector2f(RANDOM(0, x), RANDOM(0, y))), intensity(RANDOM(0, 2)), size(RANDOM(1, 5)) {};

            ~Star() = default;

        // Methods
        public:

            /**
             * @brief Generate a vector of stars
             * Generate a vector of stars with random position, intensity and size
             * Call this function for create a background of stars
             * @param x                  The x position of the window
             * @param y                  The y position of the window
             * @param nbStars            The number of stars to generate
             * @return std::vector<Star> The vector of stars
             */
            static std::vector<Star> generateStars(int x, int y, int nbStars)
            {
                std::vector<Star> stars;

                for (int i = 0; i < nbStars; i++)
                    stars.push_back(Star(x, y));
                return stars;
            }

        // Attributes
        public:

            sf::Vector2f pos; /*!< The position of the star */
            float intensity;  /*!< The intensity of the star */
            int size;         /*!< The size of the star */
    };
};

#endif /* !PLANET_HPP_ */