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

    template <typename T>
    VerticalLayout<T>::VerticalLayout(LayoutProperties properties) : properties(properties) {};

    /////////////
    // Methods //
    /////////////

    template <typename T>
    void VerticalLayout<T>::applyLayout()
    {
        sf::Vector2f position = properties.position;

        for (auto *element : _elements) {
            // Set the position of the element
            element->setPosition(position);

            // Increment the current position by element height and spacing
            position.y += element->getSie().y + properties.spacing;
        }
    }

    template <typename T>
    void VerticalLayout<T>::addElement(T &element)
    {
        _elements.push_back(&element);
    }
};
