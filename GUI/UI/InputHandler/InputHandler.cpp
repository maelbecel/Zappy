/*
** EPITECH PROJECT, 2023
** UI/UX Library
** File description:
** InputHandler
*/

#include "InputHandler.hpp"

namespace UI {
    ////////////////////
    // Public methods //
    ////////////////////
    void InputHandler::processInput(sf::RenderWindow& window)
    {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    handleKeyPress(event.key.code);
                    break;
                case sf::Event::KeyReleased:
                    handleKeyRelease(event.key.code);
                    break;
                case sf::Event::MouseButtonPressed:
                    handleMouseButtonPress(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
                    break;
                case sf::Event::MouseButtonReleased:
                    handleMouseButtonRelease(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
                    break;
                case sf::Event::MouseMoved:
                    handleMouseMove(event.mouseMove.x, event.mouseMove.y);
                    break;
                case sf::Event::MouseWheelScrolled:
                    handleMouseScroll(event.mouseWheelScroll.delta);
                    break;
                default:
                    break;
            }
        }
    }

    ////////////////////
    // Public Setters //
    ////////////////////

    void InputHandler::setKeyPressedCallback(sf::Keyboard::Key key, std::function<void()> callback)
    {
        keyPressCallbacks[key] = callback;
    }

    void InputHandler::setKeyReleasedCallback(sf::Keyboard::Key key, std::function<void()> callback)
    {
        keyReleaseCallbacks[key] = callback;
    }

    void InputHandler::setMouseButtonPressedCallback(sf::Mouse::Button button, std::function<void(int, int)> callback)
    {
        mouseButtonPressCallbacks[button] = callback;
    }

    void InputHandler::setMouseButtonReleasedCallback(sf::Mouse::Button button, std::function<void(int, int)> callback)
    {
        mouseButtonReleaseCallbacks[button] = callback;
    }

    void InputHandler::setMouseMoveCallback(std::function<void(int, int)> callback)
    {
        mouseMoveCallback = callback;
    }

    void InputHandler::setMouseScrollCallback(std::function<void(float)> callback)
    {
        mouseScrollCallback = callback;
    }

    //////////////////////
    // Private handlers //
    //////////////////////

    void InputHandler::handleKeyPress(sf::Keyboard::Key key)
    {
        if (keyPressCallbacks.count(key) > 0)
            keyPressCallbacks[key]();
    }

    void InputHandler::handleKeyRelease(sf::Keyboard::Key key)
    {
        if (keyReleaseCallbacks.count(key) > 0)
            keyReleaseCallbacks[key]();
    }

    void InputHandler::handleMouseButtonPress(sf::Mouse::Button button, int x, int y)
    {
        if (mouseButtonPressCallbacks.count(button) > 0)
            mouseButtonPressCallbacks[button](x, y);
    }

    void InputHandler::handleMouseButtonPress(sf::Mouse::Button button, sf::Vector2i pos)
    {
        if (mouseButtonPressCallbacks.count(button) > 0)
            mouseButtonPressCallbacks[button](pos.x, pos.y);
    }

    void InputHandler::handleMouseButtonRelease(sf::Mouse::Button button, int x, int y)
    {
        if (mouseButtonReleaseCallbacks.count(button) > 0)
            mouseButtonReleaseCallbacks[button](x, y);
    }

    void InputHandler::handleMouseButtonRelease(sf::Mouse::Button button, sf::Vector2i pos)
    {
        if (mouseButtonReleaseCallbacks.count(button) > 0)
            mouseButtonReleaseCallbacks[button](pos.x, pos.y);
    }

    void InputHandler::handleMouseMove(int x, int y)
    {
        if (mouseMoveCallback)
            mouseMoveCallback(x, y);
    }

    void InputHandler::handleMouseMove(sf::Vector2i pos)
    {
        if (mouseMoveCallback)
            mouseMoveCallback(pos.x, pos.y);
    }

    void InputHandler::handleMouseScroll(float delta)
    {
        if (mouseScrollCallback)
            mouseScrollCallback(delta);
    }
};
