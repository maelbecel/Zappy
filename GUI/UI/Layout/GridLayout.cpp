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
    GridLayout::GridLayout(LayoutProperties properties, size_t nbColumns) : properties(properties), _nbColumns(nbColumns) {};

    /////////////
    // Methods //
    /////////////
    void GridLayout::applyLayout()
    {
        sf::Vector2f position = properties.position;
        size_t currentColumn = 0;

        for (auto &element : _elements) {
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

    void GridLayout::addElement(std::shared_ptr<IWidget> element)
    {
        _elements.push_back(element);
    }

    std::vector<std::shared_ptr<IWidget>> GridLayout::getElements()
    {
        return _elements;
    }
};
