/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** BorderStyle
*/

#include "BorderStyle.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    BorderStyle::BorderStyle(sf::Color color, double thickness) : _borderColor(color), _borderThickness(thickness) {};

    /////////////
    // Methods //
    /////////////

    void BorderStyle::apply(sf::Drawable &drawable)
    {
        // Apply border color and thickness to the drawable element
        if (auto shape = dynamic_cast<sf::Shape *>(&drawable)) {
            shape->setOutlineColor(_borderColor);
            shape->setOutlineThickness(_borderThickness);
        }

        // TODO: Add support for other drawable types as needed (e.g. sf::Text)
    }
};
