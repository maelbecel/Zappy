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
        class Star {
            public:
                Star(const sf::Vector2f &pos, float intensity, int size) : pos(pos), intensity(intensity), size(size) {};
                Star(int x, int y) : pos(sf::Vector2f(RANDOM(0, x), RANDOM(0, y))), intensity(RANDOM(0, 2)), size(RANDOM(1, 5)) {};

                static std::vector<Star> generateStars(int x, int y, int nbStars)
                {
                    std::vector<Star> stars;

                    for (int i = 0; i < nbStars; i++)
                        stars.push_back(Star(x, y));
                    return stars;
                }

                ~Star() = default;

                sf::Vector2f pos;
                float intensity;
                int size;
        };
    };

#endif /* !PLANET_HPP_ */