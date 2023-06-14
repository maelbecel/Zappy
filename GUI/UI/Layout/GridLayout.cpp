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
    GridLayout<T>::GridLayout(LayoutProperties properties, size_t nbColumns) : properties(properties), _nbColumns(nbColumns) {};

    /////////////
    // Methods //
    /////////////

    template <typename T>
    void GridLayout<T>::applyLayout()
    {
        sf::Vector2f position = properties.position;
        size_t currentColumn = 0;

        for (auto *element : _elements) {
            // Set the position of the element
            element->setPosition(position);

            // Increment the current position by element width and spacing
            position.x += element->getSize().x + properties.spacing;

            // Increment the current column
            currentColumn++;

            // If the current column is equal to the number of columns, reset the position and increment the y position
            if (currentColumn == _nbColumns) {
                position.x = properties.position.x;
                position.y += element->getSize().y + properties.spacing;
                currentColumn = 0;
            }
        }
    }

    template <typename T>
    void GridLayout<T>::addElement(T &element)
    {
        _elements.push_back(&element);
    }
};
