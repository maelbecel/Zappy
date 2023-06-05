/*
** EPITECH PROJECT, 2023
** Zappy
** File description:
** Button
*/

#include "Button.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////

    Button::Button(IWidget *widget, std::function<void()> callback) : _widget(widget), _callback(callback) {};

    Button::Button(const Button &button) : _widget(button._widget), _callback(button._callback) {};

    /////////////
    // Methods //
    /////////////

    void Button::handleClick()
    {
        _callback();
    }

    void Button::render(sf::RenderWindow& window, ButtonState state) const
    {
        _widget->draw(window, sf::RenderStates::Default);
    }

    bool Button::isClicked(sf::Vector2f clickPosition) const
    {
        return _widget->isIn(clickPosition);
    }

    bool Button::isHovered(sf::Vector2f mousePosition) const
    {
        return _widget->isIn(mousePosition);
    }

    ///////////////////////
    // Setters & Getters //
    ///////////////////////

    void Button::setWidget(IWidget *widget)
    {
        _widget = widget;
    };

    void Button::setOnClickCallback(std::function<void()> callback)
    {
        _callback = callback;
    };

    void Button::setPosition(const sf::Vector2f& position)
    {
        _widget->setPosition(position);
    }

    sf::Vector2f Button::getPosition() const
    {
        return _widget->getPosition();
    }

    void Button::setSize(const sf::Vector2f& size)
    {
        _widget->setSize(size);
    }

    sf::Vector2f Button::getSize() const
    {
        return _widget->getSize();
    }

    ///////////////
    // Operators //
    ///////////////

    Button& Button::operator=(const Button& other)
    {
        _widget = other._widget;
        _callback = other._callback;
        return *this;
    }
};
