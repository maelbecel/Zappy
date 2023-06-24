/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** BackgroundStyle
*/

#include "BackgroundStyle.hpp"

namespace UI {

    /////////////////
    // Constructor //
    /////////////////

    BackgroundStyle::BackgroundStyle(sf::Color color) : _backgroundColor(color) {};

    ////////////
    // Method //
    ////////////

    void BackgroundStyle::apply(sf::Drawable &drawable)
    {
        // Apply background color to the drawable element
        if (auto shape = dynamic_cast<sf::Shape *>(&drawable))
            shape->setFillColor(_backgroundColor);
    }
};
