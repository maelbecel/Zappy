/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** HorizontalLayout
*/

#include "HorizontalLayout.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    template <typename T>
    HorizontalLayout<T>::HorizontalLayout(LayoutProperties properties) : ALayout<T>(properties) {};

    /////////////
    // Methods //
    /////////////

    template <typename T>
    void HorizontalLayout<T>::applyLayout()
    {
        sf::Vector2f position = _properties.position;

        for (auto *element : _elements) {
            // Set the position of the element
            element->setPosition(position);

            // Increment the current position by element width and spacing
            position.x += element->getLocalBounds().width + _properties.spacing;
        }
    }
};
