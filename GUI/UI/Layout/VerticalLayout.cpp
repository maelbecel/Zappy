/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** VerticalLayout
*/

#include "VerticalLayout.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////
    VerticalLayout::VerticalLayout(LayoutProperties properties) : properties(properties) {};

    /////////////
    // Methods //
    /////////////
    void VerticalLayout::applyLayout()
    {
        sf::Vector2f position = properties.position;

        for (auto *element : _elements) {
            // Set the position of the element
            element->setPosition(position);

            // Increment the current position by element height and spacing
            position.y += element->getSize().y + properties.spacing;
        }
    }

    void VerticalLayout::addElement(IWidget *element)
    {
        _elements.push_back(element);
    }

    std::vector<IWidget *> VerticalLayout::getElements()
    {
        return _elements;
    }
};
