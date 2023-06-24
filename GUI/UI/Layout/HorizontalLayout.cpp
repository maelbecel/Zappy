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
    HorizontalLayout::HorizontalLayout(LayoutProperties properties) : properties(properties) {};

    /////////////
    // Methods //
    /////////////
    void HorizontalLayout::applyLayout()
    {
        sf::Vector2f position = properties.position;

        for (auto &element : _elements) {
            // Set the position of the element
            element->setPosition(position);

            // Increment the current position by element width and spacing
            position.x += element->getSize().x + properties.spacing;
        }
    }

    void HorizontalLayout::addElement(std::shared_ptr<IWidget> element)
    {
        _elements.push_back(element);
    }

    std::vector<std::shared_ptr<IWidget>> HorizontalLayout::getElements()
    {
        return _elements;
    }
};
