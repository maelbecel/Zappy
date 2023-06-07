/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** Transition
*/

#include "Transition.hpp"

namespace UI {
    /////////////////
    // Constructor //
    /////////////////
    Transition::Transition(sf::RenderWindow &window, sf::Time duration) : _window(window), _duration(duration), _elapsedTime(sf::Time::Zero), _isPlaying(false), _callback(nullptr) {};

    ////////////////////
    // Public methods //
    ////////////////////

    void Transition::play(std::function<void()> transitionCallback)
    {
        _elapsedTime = sf::Time::Zero;
        _isPlaying = true;
        _callback = transitionCallback;
    }

    void Transition::update(sf::Time dt)
    {
        // Check if the transition is playing
        if (!_isPlaying)
            return;

        _elapsedTime += dt;

        // Calculate the fade value based on the elapsed time and duration
        // The fade value is a number between 0 and 1
        // It represent the percentage of the transition that is completed
        double fade = std::min(1.0f, _elapsedTime.asSeconds() / _duration.asSeconds());

        // Apply the fade effect to the window
        sf::RectangleShape fadeShape(sf::Vector2f(_window.getSize().x, _window.getSize().y));

        fadeShape.setFillColor(sf::Color(0, 0, 0, static_cast<sf::Uint8>(255 * fade)));
        _window.draw(fadeShape);

        // Check if the transition has completed
        if (_elapsedTime >= _duration) {
            _isPlaying = false;

            // Trigger the callback function if provided
            if (_callback)
                _callback();
        }
    }
};
