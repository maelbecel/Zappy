/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** GridLayout
*/

#include "GridLayout.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    template <typename T>
    GridLayout<T>::GridLayout(LayoutProperties properties, size_t nbColumns) : ALayout<T>(properties), _nbColumns(nbColumns) {};

    /////////////
    // Methods //
    /////////////

    template <typename T>
    void GridLayout<T>::applyLayout()
    {
        sf::Vector2f position = _properties.position;
        size_t currentColumn = 0;

        for (auto *element : _elements) {
            // Set the position of the element
            element->setPosition(position);

            // Increment the current position by element width and spacing
            position.x += element->getLocalBounds().width + _properties.spacing;

            // Increment the current column
            currentColumn++;

            // If the current column is equal to the number of columns, reset the position and increment the y position
            if (currentColumn == _nbColumns) {
                position.x = _properties.position.x;
                position.y += element->getLocalBounds().height + _properties.spacing;
                currentColumn = 0;
            }
        }
    }
};
